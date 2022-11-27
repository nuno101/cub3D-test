/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:01:45 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/27 17:16:21 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		error(EXT_ERR);
	if (ft_strncmp(path + len - 4, ".cub", 4))
		error(EXT_ERR);
}

int	error(int err)
{
	ft_putendl_fd("error", STDERR);
	if (err == FILE_ERR)
		perror("File does not open: ");
	else if (err == MALLOC_ERR)
		perror("Malloc failed: ");
	else if (err == RGB_ERR)
		ft_putendl_fd("RGB is not digit", STDERR);
	else if (err == RGB_OUT_OF_BOUNDS)
		ft_putendl_fd("RGB is out of range", STDERR);
	else if (err == RGB_TOO_MANY)
		ft_putendl_fd("RGB too many numbers given", STDERR);
	else if (err == RGB_TOO_FEW)
		ft_putendl_fd("RGB too few numbers given", STDERR);
	else if (err == MAP_DUP_ERR)
		ft_putendl_fd("Map have dublicated utility", STDERR);
	else if (err == MAP_NOT_CLOSED)
		ft_putendl_fd("Map is not closed", STDERR);
	else if (err == EXT_ERR)
		ft_putendl_fd("Map extension is not .cub", STDERR);
	else if (err == MAP_ERR)
		ft_putendl_fd("Map error", STDERR);
	else
		perror(NULL);
	exit(1);
}
