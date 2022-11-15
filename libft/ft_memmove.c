/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:51:04 by jjesberg          #+#    #+#             */
/*   Updated: 2021/08/30 18:34:25 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	size_t				j;
	char				*src2;
	char				*dest2;

	i = 0;
	j = n;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (!src2 && !dest2)
		return (NULL);
	if (dest2 > src2)
	{
		while (j-- > 0)
		{
			((char *)dest2)[j] = ((char *)src2)[j];
		}
	}
	while (i < n && src2 > dest2)
	{
		((char *)dest2)[i] = ((char *)src2)[i];
		i++;
	}
	return (dest);
}
