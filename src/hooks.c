/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:11:23 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 16:13:34 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	screensize(t_cub *cub)
{
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	mlx_get_monitor_size(0, &cub->s_width, &cub->s_height);
	mlx_terminate(cub->mlx);
	cub->mlx = mlx_init(cub->s_width, cub->s_height, "Cub3D", true);
}

void	set_ray(int x, t_ray *ray, t_cub *cub)
{
	ray->camera = (double)((2 * x) / (double)cub->s_width - 1);
	ray->ray_dir.x = ray->dir.x + (ray->plane.x * ray->camera);
	ray->ray_dir.y = ray->dir.y + (ray->plane.y * ray->camera);
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->map.x = ray->pos.x;
	ray->map.y = ray->pos.y;
}

void	check_dist(t_ray *ray)
{
	ray->hit = 0;
	ray->step.x = 1;
	ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	ray->step.y = 1;
	ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
	}
}

//TODOO 25lines FIX
void	dda(t_cub *cub, t_ray *ray)
{
	int is_x_side;
	int is_negative;

	while (ray->hit == 0 && !cub->exit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			is_x_side = 1;
			is_negative = ray->ray_dir.x < 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			is_x_side = 0;
			is_negative = ray->ray_dir.y < 0;
		}
		if (is_x_side && is_negative)
			ray->side = NO;
		else if (is_x_side && !is_negative)
			ray->side = SO;
		else if (!is_x_side && is_negative)
			ray->side = EA;
		else
			ray->side = WE;
		if (cub->d->map[ray->map.x][ray->map.y] > '0')
			ray->hit = 1;
	}
	if (ray->side == NO || ray->side == SO)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
}


static int	get_tex_x(t_cub *cub)
{
	double	x;
	int		tex_x;

	if (cub->ray->side == 0 || cub->ray->side == 1)
		x = cub->ray->pos.y + cub->ray->perp_wall_dist * cub->ray->ray_dir.y;
	else
		x = cub->ray->pos.x + cub->ray->perp_wall_dist * cub->ray->ray_dir.x;
	x -= floor(x);
	tex_x = x * cub->d->textures[cub->ray->side]->width;
	if ((cub->ray->side == 0 && cub->ray->ray_dir.x > 0) \
	|| (cub->ray->side == 1 && cub->ray->ray_dir.y < 0))
		tex_x = cub->d->textures[cub->ray->side]->width - tex_x - 1;
	return (tex_x);
}

void	texturize(t_cub *cub, int x, int start, int end)
{
	int				line_h;
	double			step;
	double			text_pos;
	mlx_texture_t	*texture;

	step = 0;
	texture = cub->d->textures[cub->ray->side];
	cub->d->tmp[0] = get_tex_x(cub);
	line_h = end - start;
	start = fmax(0, cub->s_height / 2 - line_h / 2);
	text_pos = (start - cub->s_height / 2 + line_h / 2) * step;
	step = 1.0 * texture->height / line_h;
	while (start < end)
	{
		cub->d->tmp[1] = (int)text_pos & (texture->height - 1);
		text_pos += step;
		ft_memcpy(&cub->image->pixels[((start * cub->image->width + x) * 4)],\
		&texture->pixels[((cub->d->tmp[1]) * texture->height + (cub->d->tmp[0])) * 4], 4);
		start++;
	}
}


void	draw_ray(int x, t_cub *cub, t_ray *ray)
{
	int	line_height;
	int	start;
	int	end;
	int	i;

	line_height = 0;
	if (ray->perp_wall_dist > 0)
		line_height = (int)(cub->s_height / ray->perp_wall_dist);
	start = cub->s_height / 2 - cub->s_height / 2;
	end = line_height / 2 + cub->s_height / 2;
	if (end >= cub->s_height)
		end = cub->s_height - 1;
	texturize(cub, x, start, end);
	i = 0;
	while (i < cub->s_height && !cub->exit)
	{
		if (i < start)
			mlx_put_pixel(cub->image, x, i, cub->c);
		if (i > end)
			mlx_put_pixel(cub->image, x, i, cub->f);
		i++;
	}
}

void	render_ray(void	*param)
{
	t_cub	*cub;
	int		x;

	x = 0;
	cub = (t_cub *)param;
	while (x < cub->s_width && !cub->exit)
	{
		set_ray(x, cub->ray, cub);
		check_dist(cub->ray);
		dda(cub, cub->ray);
		draw_ray(x, cub, cub->ray);
		x++;
	}	
}

void	hooks(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, &render_ray, cub);
	mlx_key_hook(cub->mlx, &cub_keys, cub);
	mlx_resize_hook(cub->mlx, &resize_screen, cub);
	mlx_loop(cub->mlx);
}
