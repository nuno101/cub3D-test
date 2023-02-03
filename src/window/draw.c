/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:57 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/03 17:23:26 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * update sreen sixe in cub struct
 */
void	handle_screen_resize(int32_t x, int32_t y, void *param)
{
	t_cub		*cub;
	static int	i;

	cub = (t_cub *)param;
	if (VERBOSE > 2)
	{
		if (i >= 0)
			i++;
		else
			i = 0;
		if (i != 1)
			printf("DEBUG: Resizing screen... %i \n", i);
	}
	cub->s_width = x;
	cub->s_height = y;
}

/*
 * Calculates the texture position 
 * for the current ray based on the wall distance and ray direction.
*/
static int	tex_pos(t_cub *cub)
{
	double	x;
	int		tex_x;

	if (cub->ray->side == NO || cub->ray->side == SO)
		x = cub->ray->pos.y + cub->ray->wall_distance * cub->ray->ray_dir.y;
	else
		x = cub->ray->pos.x + cub->ray->wall_distance * cub->ray->ray_dir.x;
	x -= floor(x);
	tex_x = x * cub->d->textures[cub->ray->side]->width;
	if ((cub->ray->side == NO && cub->ray->ray_dir.x > 0) \
	|| (cub->ray->side == SO && cub->ray->ray_dir.y < 0))
		tex_x = cub->d->textures[cub->ray->side]->width - tex_x - 1;
	return (tex_x);
}

/*
 * texturizes the wall by taking in a ray casting structure, 
 * screen width position, start and end positions of the wall, 
 * and a texture structure. It calculates the step size, 
 * texture position, and the line height of the wall. 
 * Then, it uses these values to map the wall texture onto the screen 
 * by copying the pixel values from the texture to the image buffer.
 *
 * step: how much to increase the texture coordinate per screen pixel 
 * tex_p: texture coordinate
 */
static void	texturize(t_cub *cub, int x, int start, int end)
{
	int				line_h;
	double			step;
	double			tex_p;
	mlx_texture_t	*tex;
	int				tmp;

	tex = cub->d->textures[cub->ray->side];
	line_h = end - start;
	start = fmax(0, (cub->s_height - line_h) / 2);
	step = 1.0 * tex->height / line_h;
	tex_p = (start - (cub->s_height + line_h) / 2) * step;
	while (start < end)
	{
		tmp = (int)tex_p & (tex->height - 1);
		tex_p += step;
		ft_memcpy(&cub->image->pixels[((start * cub->image->width + x) * 4)], \
		&tex->pixels[(tmp * tex->height + tex_pos(cub)) * 4], 4);
		start++;
	}
}

/*
 * It calculates the line height and starts/ends based on the wall distance, 
 * then applies textures to the walls, and finally colours the floor and ceiling.
 */
void	draw_ray(int x, t_cub *cub, t_ray *ray)
{
	int	line_height;
	int	start;
	int	end;
	int	i;

	line_height = 0;
	if (ray->wall_distance > 0)
		line_height = (int)(cub->s_height / ray->wall_distance);
	start = (cub->s_height - line_height) / 2;
	end = (line_height + cub->s_height) / 2;
	if (end >= cub->s_height)
		end = cub->s_height - 1;
	texturize(cub, x, start, end);
	i = 0;
	while (i < cub->s_height)
	{
		if (i <= start)
			mlx_put_pixel(cub->image, x, i, cub->c_colour);
		if (i >= end)
			mlx_put_pixel(cub->image, x, i, cub->f_colour);
		i++;
	}
}
