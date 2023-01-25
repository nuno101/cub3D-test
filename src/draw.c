/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:57 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/25 15:21:07 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	tex_pos(t_cub *cub)
{
	double	x;
	int		tex_x;

	if (cub->ray->side == 0 || cub->ray->side == 1)
		x = cub->ray->pos.y + cub->ray->wall_distance * cub->ray->ray_dir.y;
	else
		x = cub->ray->pos.x + cub->ray->wall_distance * cub->ray->ray_dir.x;
	x -= floor(x);
	tex_x = x * cub->d->textures[cub->ray->side]->width;
	if ((cub->ray->side == 0 && cub->ray->ray_dir.x > 0) \
	|| (cub->ray->side == 1 && cub->ray->ray_dir.y < 0))
		tex_x = cub->d->textures[cub->ray->side]->width - tex_x - 1;
	return (tex_x);
}

static void	texturize(t_cub *cub, int x, int start, int end)
{
	int				line_h;
	double			step;
	double			text_pos;
	mlx_texture_t	*texture;

	step = 0;
	texture = cub->d->textures[cub->ray->side];
	cub->d->tmp[0] = tex_pos(cub);
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
	if (ray->wall_distance > 0)
		line_height = (int)(cub->s_height / ray->wall_distance);
	start = cub->s_height / 2 - line_height / 2;
	end = line_height / 2 + cub->s_height / 2;
	if (end >= cub->s_height)
		end = cub->s_height - 1;
	texturize(cub, x, start, end);
	i = 0;
	while (i < cub->s_height)
	{
		if (i < start)
			mlx_put_pixel(cub->image, x, i, cub->c);
		if (i > end)
			mlx_put_pixel(cub->image, x, i, cub->f);
		i++;
	}
}