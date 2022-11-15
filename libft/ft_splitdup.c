/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:56:24 by jjesberg          #+#    #+#             */
/*   Updated: 2022/10/21 15:01:45 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitdup(char **s)
{
	char	**new;
	int		len;
	int		i;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	len = ft_splitlen(s);
	new = malloc(sizeof(char *) * (len + 1));
	while (i < len && s[i])
	{
		new[i] = ft_strdup(s[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
