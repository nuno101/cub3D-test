/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:16:26 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/10 17:36:29 by ezpiro-m         ###   ########.fr       */
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
