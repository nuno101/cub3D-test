/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:44:07 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 11:01:11 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

//FIXME - temporarily remove static to allow unit testing
//static bool	valid_colour(char *s)
bool	valid_colour(char *s)
{
	int		i;
	int		tmp;
	int		count;

	count = 0;
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i] != 9)
			return (0);
		if (ft_isdigit(s[i]))
		{
			tmp = ft_atoi(s + i);
			if (tmp > 255 || tmp < 0)
				return (0);
			while (s[i] && ft_isdigit(s[i]))
				i++;
			count++;
			i--;
		}
		i++;
	}
	if (count != 3)
		return (0);
	return (1);
}

static uint32_t	get_colour(char *s)
{
	int			i;
	int			j;
	int			tmp[3];

	j = 0;
	i = 0;
	ft_bzero(tmp, 3);
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
	printf("colour = %x\n", (uint32_t)(tmp[0] << 24 | tmp[1] << 16 | tmp[2] << 8 | 255));
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
