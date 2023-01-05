/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/05 07:48:24 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "structs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "macros.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//debugtools/print_all.c
void	print_map_param(t_data *data);

//init/init.c (4)
t_cub	*init_cub(t_data *data);
t_data	*init_data(int argc, char *argv[]);

//init/save_map_data.c (3)
int		find_map(char *map);
int		save_colours(char *s, t_data *data);

//init/bools_map.c (5) full
int		is_cardinal_direction(char c, char *s);
bool	is_surrounded_num(int i, int j, t_data *data);
bool	is_surrounded(int i, int j, t_data *data);
bool	is_player(char c);
bool 	check_surrounded_player(t_data *data);

//init/save_map.c (5) full
void 	save_cardinal_direction(t_data *data, int i, int j, int ret);
int		save_param(t_data *data);

//init/valid_map.c (5) full
int		check_params(t_data *data);

//valid_map_helper.c (3)
int	check_map(t_data *data);

//tools/utils.c (4)
void	screensize(t_cub *m);
int		sp_dg_skipper(char *s, int *i);
void	clean_mlx(t_cub *m);
void	free_data(t_data *data);

//tools/error.c
int		error(int err);

//tools/render.c
void	skyline(t_cub *m);
void	render_map(void	*param);

//src/start_cub.c
void	start_cub(t_data *data);

//src/keys.c
void	cub_keys(mlx_key_data_t key, void *param);

#endif