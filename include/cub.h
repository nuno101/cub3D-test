/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/19 10:41:51 by nlouro           ###   ########.fr       */
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
void			print_data(t_data *data);
void			print_cub(t_cub *cub);
int				cub_error(int err);
int				cub_error_2(int err);

//parser/checks.c
int				find_path_type(char *s);

//parser/player_check.c
void			player_checks(t_data *data);

//parser/wall_check.c
void			wall_check(t_data *data);

//parser/init_data.c (FULL)
void			map_data(char *map_path, t_data *data);

//parser/bools.c
bool			validate_mapchars(char **map);
bool			valid_map_border(char *s);
bool			is_mapchar(char c);
bool			is_player(char c);

//parser/colours.c
void			check_colours(t_data *data, char *s);
//parser/textures.c
mlx_texture_t	*save_texture(char *s);

//src/start_cub.c
void			start_cub(t_data *data);
void			skyline(t_cub *cub);
void			clean_mlx(t_cub *cub);

//src/hooks.c
void			hooks(t_cub *cub);
void			screensize(t_cub *cub);

//src/keys.c
void			cub_keys(mlx_key_data_t key, void *param);
void			resize_screen(int32_t x, int32_t y, void *param);

//src/player_pos.c
void			player_pos(t_cub *cub, t_data *data);

//src/cleaner.c
void			free_data(t_data *data);
void			clean_mlx(t_cub *cub);
void			free_cub(t_cub *cub);

#endif
