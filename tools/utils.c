/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:16:21 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 08:09:01 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	screensize(t_cub *m)
{
	if (!m->mlx)
		exit(error(MLX_ERROR));
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	mlx_terminate(m->mlx);
	m->mlx = mlx_init(m->s_width, m->s_height, "Cub3D", true);
}

int	sp_dg_skipper(char *s, int *i)
{
	while (ft_isdigit(s[*i]))
		(*i)++;
	if (s[*i] != ' ' && s[*i] != ',' && s[*i] != '\0')
		return (COLOUR_ERROR);
	while (s[*i] && (s[*i] <= 32 || s[*i] == ','))
		(*i)++;
	return (0);
}

void	clean_mlx(t_cub *m)
{
	free_data(m->d);
	mlx_delete_image(m->mlx, m->image);
	mlx_delete_texture(m->_NO);
	mlx_delete_texture(m->_SO);
	mlx_delete_texture(m->_WE);
	mlx_delete_texture(m->_EA);
	mlx_terminate(m->mlx);
	free(m);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	if (data->_NO)
		free(data->_NO);
	if (data->_SO)
		free(data->_SO);
	if (data->_WE)
		free(data->_WE);
	if (data->_EA)
		free(data->_EA);
	if (data->map_values)
		ft_cleansplit(data->map_values);
	free(data->map);
	free(data);
}
