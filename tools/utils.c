/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:16:21 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 10:13:58 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

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

void	free_data(t_data *data)
{
	int i = 0;
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
