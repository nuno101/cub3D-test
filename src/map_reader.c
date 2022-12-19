/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:18 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 06:51:56 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

static int	is_cardinal_direction(char c, char *s)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N' && s[1] && s[1] == 'O')
			return (NO);
		if (c == 'S' && s[1] && s[1] == 'O')
			return (SO);
		if (c == 'W' && s[1] && s[1] == 'E')
			return (WE);
		if (c == 'E' && s[1] && s[1] == 'A')
			return (EA);
	}
	return (0);
}

static void	save_path(char *path, t_data *data, int dir)
{
	int		i;

	i = 0;
	while (path[i] && !ft_isalpha(path[i]) && path[i] != '.')
		i++;
	switch (dir)
	{
		case (NO):
		{
			data->_NO = ft_strdup(path + i);
			break ;
		}
		case (SO):
		{
			data->_SO = ft_strdup(path + i);
			break ;
		}
		case (WE):
		{
			data->_WE = ft_strdup(path + i);
			break ;
		}
		case (EA):
		{
			data->_EA = ft_strdup(path + i);
			break ;
		}
	}
}

static void	save_colours(char *s, t_data *data)
{
	int *ptr;
	int	i;
	int	j;

	j = 0;
	i = 1;	
	if (s[0] == 'C')
		ptr = data->C;
	if (s[0] == 'F')
		ptr = data->F;
	while (j < 3)
	{
		sp_dg_skipper(s, &i);
		ptr[j++] = ft_atoi(s + i);
	}
}

/*
just save parameter
*/
int	map_reader(t_data *data)
{
	int		i;
	int		j;
	int		ret;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			ret	= is_cardinal_direction(data->map[i][j], data->map[i] + j);
			if (ret)
			{
				j++;
				if (data->map[i][j] && data->map[i][j + 2] != '\0')
				{
					save_path(data->map[i] + j + 1, data, ret);
				}
			}
			else if (data->map[i][j] == 'F' || data->map[i][j] == 'C')
				save_colours(data->map[i] + j, data);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	map_reader2(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			j += write(1, &data->map[i][j], 1);
		}
		j = 0;
		i++;
	}
	return (INVALID_MAP);
	return (0);
}