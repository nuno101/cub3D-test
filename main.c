/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/07 17:45:15 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	screensize(t_cub *m)
{
	if (!m->mlx)
		exit(cub_error(MLX_ERROR));
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	mlx_terminate(m->mlx);
	m->mlx = mlx_init(m->s_width, m->s_height, "Cub3D", true);
}

void	clean_mlx(t_cub *m)
{
	mlx_delete_image(m->mlx, m->image);
	mlx_terminate(m->mlx);
	free(m);
}
static t_ray	*init_ray(t_cub *m, float r_angle, t_coords pos)
{
	t_ray	*ray;

	(void)pos;
	(void)r_angle;
	(void)m;
	ray = malloc(sizeof(t_ray));

	return (ray);
}

void	skyline(t_cub *m)
{
	int32_t			i;

	i = 0;
	while (i < m->s_width * m->s_height)
	{
		if (i < m->s_width * (m->s_height / 2))
			mlx_put_pixel(m->image, i, 0, m->d->c_colour);
		else
			mlx_put_pixel(m->image, i, 0, m->d->f_colour);
		i++;
	}
}

float	ray_angle_fix(t_cub *m, int i)
{
	float	screen_halflen;
	float	seg_len;

	screen_halflen = tanf(m->fov / 2);
	seg_len = screen_halflen / (m->s_width / 2);
	return (atanf(seg_len * i - screen_halflen));
}

void	cub_keys(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	(void)key;
	tmp = (t_cub*)param;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
	{
		clean_mlx(tmp);
		exit (cub_error(EXIT_SUCCESS));
	}
}

static void	resize_screen(int32_t x, int32_t y, void *param)
{
	t_cub 			*m;

	m = (t_cub*)param;
	m->s_width = x;
	m->s_height = y;
	skyline(m); //maybe leaks because we overwrite old images
}

void	render_ray(void	*param)
{
	t_cub	*m;
	int		i;
	float	r_angle;

	m = (t_cub*)param;
	i = 0;
	m->ray = malloc(sizeof(t_ray) * (m->s_width + 1));
	if (!m->ray)
		exit(cub_error(MALLOC_ERROR));
	while (i < m->s_width)
	{
		r_angle = m->player_angle + ray_angle_fix(m, i);
		m->ray[i] = init_ray(m, r_angle, m->player_pos);
		i++;
	}
	m->ray[i] = NULL;
}

static void	hooks(t_cub *m)
{
	mlx_key_hook(m->mlx, &cub_keys, m);
	mlx_resize_hook(m->mlx, &resize_screen, m);
	mlx_loop_hook(m->mlx, &render_ray, m);
	mlx_loop(m->mlx);
}

t_cub	*init_cub(t_data *data)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	cub->d = data;
	cub->mlx = mlx_init(100, 100, "MLX", true);
	screensize(cub);
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	cub->image = mlx_new_image(cub->mlx, cub->s_width, cub->s_height);
	if (!cub->image)
		exit(cub_error(MLX_ERROR));
	cub->player_angle = 11;
	cub->player_pos.x = 2;
	cub->player_pos.y = 2;
	cub->fov = 2 * atan(0.66 / 1.0);
	cub->ray = NULL;
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	return (cub);
}

void	start_cub(t_data *data)
{
	t_cub	*cub;

	cub = init_cub(data);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		exit(cub_error(MLX_ERROR));
	skyline(cub);
	hooks(cub);
	clean_mlx(cub);
	exit(cub_error(EXIT_SUCCESS));
}

int main(int argc, char **argv)
{
    t_data *data;

    if (argc < 2 || check_arg(argv[1]))
        return (cub_error(ARG_ERROR));
    data = init_data(argv);
	start_cub(data);
    return (cub_error(0));
}
