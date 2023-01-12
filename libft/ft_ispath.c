/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:16:26 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 16:30:17 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ispath(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd >= 0)
		close(fd);
	else
		return (0);
	return (1);
}
