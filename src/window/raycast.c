/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:17:53 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/02 13:45:59 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * This function sets up a single ray,
 * ready to be cast into the cub3D world 
 * and determine what is visible to the player.
*/
static void	set_ray(int x, t_ray *ray, t_cub *cub)
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

/*
 * calculates the distance the ray must travel in the x and y directions 
 * in order to determine what objects it will hit in the game world.
*/
static void	calculate_ray_distance(t_ray *ray)
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

/*
 * dda() helper to comply w/ norm
 * sets the side and wall distance of the ray,
 * based on whether the x-side or y-side of the map was hit,
 * and whether the direction of the ray was negative or positive.
 */
void	set_ray_side_and_w_distance(t_ray *ray, int is_x_side, int is_negative)
{
	if (is_x_side)
	{
		if (is_negative)
			ray->side = NO;
		else
			ray->side = SO;
	}
	else
	{
		if (is_negative)
			ray->side = EA;
		else
			ray->side = WE;
	}
	if (is_x_side)
		ray->wall_distance = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_distance = ray->side_dist.y - ray->delta_dist.y;
}

/*
 * Digital Differential Analysis
 * wall_distance = perpWallDist;
 * DDA algorithm 
 * to trace the path of a ray 
 * and determine the closest wall it intersects.
 */
static void	dda(t_cub *cub, t_ray *ray)
{
	int	is_x_side;
	int	is_negative;

	while (ray->hit == 0)
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
		if (cub->d->map[ray->map.x][ray->map.y] > '0')
			ray->hit = 1;
	}
	set_ray_side_and_w_distance(ray, is_x_side, is_negative);
}

/*
 * rendering the rays and determining 
 * what is visible to the player in the game world. 
 * It loops through the screen width and for each column, 
 * sets up the ray, calculates the distance, 
 * and performs the DDA algorithm to find the first wall intersection. 
 * Finally, it draws the ray on the screen.
*/
void	render_ray(void *param)
{
	t_cub	*cub;
	int		i;

	i = 0;
	cub = (t_cub *)param;
	while (i < cub->s_width)
	{
		set_ray(i, cub->ray, cub);
		calculate_ray_distance(cub->ray);
		dda(cub, cub->ray);
		draw_ray(i, cub, cub->ray);
		i++;
	}
}
