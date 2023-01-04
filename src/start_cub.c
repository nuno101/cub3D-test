/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/04 23:07:34 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	key_press(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	if (key.key == MLX_KEY_ESCAPE)
	{
		tmp = (t_cub*)param;
		clean_mlx(tmp);
		exit(0);
	}
}

void	start_cub(t_data *data)
{
	t_cub	*m;

	m = init_cub(data);
	mlx_key_hook(m->mlx, &key_press, m);
	mlx_loop(m->mlx);
	clean_mlx(m);
	exit(error(0));
}
