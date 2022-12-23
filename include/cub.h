/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/12/23 06:28:13 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "structs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "error.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//debugtools/print_all.c
void	print_map_param(t_data *data);

//tools/utils.c
void	free_data(t_data *data);
int		sp_dg_skipper(char *s, int *i);

//tools/bools.c
int		is_cardinal_direction(char c, char *s);
bool	is_surrounded_num(int i, int j, t_data *data);
bool	is_surrounded(int i, int j, t_data *data);
bool	is_player(char c);
bool 	check_surrounded_player(t_data *data);

//tools/save.c
void 	save_cardinal_direction(t_data *data, int i, int j, int ret);
int		save_param(t_data *data);

//src/init.c / (4)
int		init_map(int argc, char **argv, t_data *data);
int		find_map(char *map);
int		save_colours(char *s, t_data *data);

//src/valid.c
int		check_params(t_data *data);

//src/map_reader.c
int		map_reader(t_data *data);

#endif