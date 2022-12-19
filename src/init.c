/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:12 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 07:09:21 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

/*save map in struct(data.map) via get_next_line*/
int	init_map(int argc, char **argv, t_data *data)
{
	int fd;
	int i;

	if (argc < 2)
		return (ARG_ERROR);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	data->argc = argc;
	data->argv = argv;
	data->map = malloc(sizeof(char *) * (80));
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
		{
			data->map[i] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}

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
			if (data->_NO[ft_strlen(data->_NO) - 1] == '\n')
				data->_NO[ft_strlen(data->_NO) - 1] = '\0';
			break ;
		}
		case (SO):
		{
			data->_SO = ft_strdup(path + i);
			if (data->_SO[ft_strlen(data->_SO) - 1] == '\n')
				data->_SO[ft_strlen(data->_SO) - 1] = '\0';
			break ;
		}
		case (WE):
		{
			data->_WE = ft_strdup(path + i);
			if (data->_WE[ft_strlen(data->_WE) - 1] == '\n')
				data->_WE[ft_strlen(data->_WE) - 1] = '\0';
			break ;
		}
		case (EA):
		{
			data->_EA = ft_strdup(path + i);
			if (data->_EA[ft_strlen(data->_EA) - 1] == '\n')
				data->_EA[ft_strlen(data->_EA) - 1] = '\0';
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
int	save_param(t_data *data)
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
