/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:50:49 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/21 14:30:49 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	ft_isdigit_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_contains_only(char *s, char *set)
{
	while (*s)
	{
		if (!ft_strchr(set, *s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_occurence(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

int	within(char *s, char *set)
{
	while (*s)
	{
		if (ft_strchr(set, *s))
			return (1);
		s++;
	}
	return (0);
}
