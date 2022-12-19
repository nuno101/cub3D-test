/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:16:21 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 06:49:31 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	sp_dg_skipper(char *s, int *i)
{
	while (ft_isdigit(s[*i]))
		(*i)++;
	while (s[*i] && (s[*i] <= 32 || s[*i] == ','))
		(*i)++;
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
	free(data->map);
	free(data);
}
