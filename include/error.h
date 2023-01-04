/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:02:43 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/04 17:55:26 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub.h"

# define ARG_ERROR      11
# define INVALID_MAP    12
# define MALLOC_ERROR   13
# define DIR_ERROR      14
# define COLOUR_ERROR	15
# define MAP_ERROR      16

int	error(int err);

#endif