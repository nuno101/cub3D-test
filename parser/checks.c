/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:23:03 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 23:52:57 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_text(char **map, int *tx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!ft_strncmp(map[i] + j, "NO ", 3))
				tx[0] += 1;
			else if (!ft_strncmp(map[i] + j, "SO ", 3))
				tx[1] += 1;
			else if (!ft_strncmp(map[i] + j, "EA ", 3))
				tx[2] += 1;
			else if (!ft_strncmp(map[i] + j, "WE ", 3))
				tx[3] += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (tx[0] != 1 || tx[1] != 1 || tx[2] != 1 || tx[3] != 1)
		return (1);
	return (0);
}

int	find_path_type(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, "NO ", 3))
			return (NO);
		else if (!ft_strncmp(s + i, "SO ", 3))
			return (SO);
		else if (!ft_strncmp(s + i, "EA ", 3))
			return (EA);
		else if (!ft_strncmp(s + i, "WE ", 3))
			return (WE);
		i++;
	}
	return (0);
}
