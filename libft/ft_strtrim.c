/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:26:43 by jjesberg          #+#    #+#             */
/*   Updated: 2021/08/30 19:02:28 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	j;
	char	*arr;

	start = 0;
	while (s1[start] && ft_inset(s1[start], set))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && ft_inset(s1[end - 1], set))
	{
		end--;
	}
	arr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!arr)
		return (NULL);
	j = 0;
	while (start < end)
	{
		arr[j++] = s1[start++];
	}
	arr[j] = 0;
	return (arr);
}
