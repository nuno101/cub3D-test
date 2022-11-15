/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:06:21 by jjesberg          #+#    #+#             */
/*   Updated: 2021/10/12 17:42:12 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*arr;

	j = 0;
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	while (j < ft_strlen(s1))
	{
		arr[j] = s1[j];
		j++;
	}
	while (i < ft_strlen(s2))
		arr[j++] = s2[i++];
	arr[j] = '\0';
	return (arr);
}
