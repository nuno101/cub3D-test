/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:35:11 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 09:35:46 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	is_cardinal_direction(char c, char *s)
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
