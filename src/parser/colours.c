/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:44:07 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/04 12:55:33 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * check if a given string (s) is a valid color in the format "R, G, B"
 * where R, G, and B are integers between 0 and 255 (inclusive)
 * start at i = 1 to skip F or C specifier
 * return nr of colors which should be 3 for a valid R,G,B color
 * NOTE: this function is not declared static to allow unit testing
 */
int	valid_colours(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ')
			return (0);
		if (ft_isdigit(s[i]))
		{
			if (ft_atoi(s + i) > 255 || ft_atoi(s + i) < 0)
				return (0);
			while (s[i] && ft_isdigit(s[i]))
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

/*
 * iterate through the the input string. if a digit is found, converts that 
 * character to an integer. Then use ft_atoi and assign it to the next element
 * in the "rgb" array (decimal part is discarded)
 * continue until all digits in the input string have been processed.
 * shifts the values in the "rgb" array to the left by 24, 16, and 8 bits
 * respectively and ORs them together
 */
static uint32_t	get_colour(char *s)
{
	int			i;
	int			j;
	int			rgb[3];

	j = 0;
	i = 0;
	ft_bzero(rgb, 3);
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			rgb[j++] = ft_atoi(s + i);
			while (s[i] && ft_isdigit(s[i]))
				i++;
		}
		i++;
	}
	return ((uint32_t)(rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 255));
}

void	check_colours(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, "F ", 2) && valid_colours(s + i) == 3)
		{
			if (data->f_colour > 0)
				exit(cub_error(COLOUR_PRESENCE_ERROR));
			else
				data->f_colour = get_colour(s + i);
		}
		else if (!ft_strncmp(s + i, "C ", 2) && valid_colours(s + i) == 3)
		{
			if (data->c_colour > 0)
				exit(cub_error(COLOUR_PRESENCE_ERROR));
			else
				data->c_colour = get_colour(s + i);
		}
		i++;
	}
}
