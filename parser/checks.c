/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:23:03 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:13 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * find texture code
 */
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
	return (NONE);
}
