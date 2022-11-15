/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:00:25 by jjesberg          #+#    #+#             */
/*   Updated: 2022/08/01 19:26:57 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	arr = malloc(size * nmemb);
	i = 0;
	if (!arr)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}
