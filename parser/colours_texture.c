/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:44:07 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/07 03:15:39 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static mlx_texture_t	*save_text(char *s)
{
	mlx_texture_t	*tmp;
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (!ft_ispath(s + i))
				exit(cub_error(TEX_PATH_ERROR));
			else
			{
				tmp = mlx_load_png(s + i);
				if (!tmp)
					exit(cub_error(TEX_PATH_ERROR));
				break ;
			}
		}
		i++;
	}
	return (tmp);
}

void	init_texture(t_data *data, char *s, int mod)
{
	if (mod == NO)
		data->textures[0] = save_text(s);
	if (mod == SO)
		data->textures[0] = save_text(s);
	if (mod == WE)
		data->textures[0] = save_text(s);
	if (mod == EA)
		data->textures[0] = save_text(s);
}

static bool	valid_colour(char *s)
{
	int		i;
	int		tmp;

	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i] != 9)
		{
			return (0);
		}
		if (ft_isdigit(s[i]))
		{
			tmp = ft_atoi(s + i);
			if (tmp > 255 || tmp < 0)
				return (0);
			while (s[i] && ft_isdigit(s[i]))
				i++;
			i--;
		}
		i++;
	}
	return (1);	
}

static uint32_t	get_colour(char *s)
{
	int			i;
	int			j;
	int			tmp[3];

	j = 0;
	i = 0;
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			tmp[j++] = ft_atoi(s + i);
			while (s[i] && ft_isdigit(s[i]))
				i++;
		}
		i++;
	}
	return ((uint32_t)(tmp[0] << 24 | tmp[1] << 16 | tmp[2] << 8 | 255));
}

void	check_colours(t_data *data, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, "F ", 2) && valid_colour(s + i))
		{
			data->f_colour = get_colour(s + i);
		}
		else if (!ft_strncmp(s + i, "C ", 2) && valid_colour(s + i))
		{
			data->c_colour = get_colour(s + i);
		}
		i++;
	}
}
