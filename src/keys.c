/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:34:32 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 05:22:30 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	cub_keys(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	(void)key;
	tmp = (t_cub*)param;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
	{
		clean_mlx(tmp);
		exit (error(EXIT_SUCCESS));
	}
}
