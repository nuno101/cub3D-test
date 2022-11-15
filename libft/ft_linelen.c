/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 01:13:54 by jjesberg          #+#    #+#             */
/*   Updated: 2022/10/18 07:09:51 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linelen(int fd2)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd2);
	if (!line)
		return (-1);
	else
		i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd2);
		if (line == NULL)
		{
			if (i > 1)
				i--;
			break ;
		}
		i++;
	}
	if (line)
		free(line);
	return (i);
}
