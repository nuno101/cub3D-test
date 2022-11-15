/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:02:11 by jjesberg          #+#    #+#             */
/*   Updated: 2021/10/13 15:09:05 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + slen);
	while (slen--)
	{
		if (*(s + slen) == (char) c)
			return ((char *) s + slen);
	}
	return (0);
}
