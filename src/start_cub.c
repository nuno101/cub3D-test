/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/03 17:48:06 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"


static int	screensize(t_cub *m)
{
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	return 0;
}

void	key_press(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	printf("key = %i\n", key.key);
	if (key.key == 256)
	{
		tmp = (t_cub*)param;
		mlx_terminate(tmp->mlx);
		free_data(tmp->d);
		free(tmp);
		system("leaks cub3D");
		exit(0);
	}

}


void	x_button(void *param)
{
	t_cub	*tmp;

	tmp = (t_cub*)param;
	mlx_terminate(tmp->mlx);
	free_data(tmp->d);
	free(tmp);
	system("leaks cub3D");
	exit(0);
}

int	start_cub(t_data *data)
{
	t_cub	*m;

	m = malloc(sizeof(t_cub));
	m->d = data;
	m->mlx = mlx_init(100, 100, "MLX", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	screensize(m);
	mlx_terminate(m->mlx);
	m->mlx = mlx_init(m->s_width, m->s_height, "Cub3D", true);
	mlx_key_hook(m->mlx, &key_press, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	free(m);
	return (0);
}