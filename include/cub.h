/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:57:55 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 16:48:16 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "structs.h"
# include "macros.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// parser/ - .cub map filenames parsing 
void			parse_map_data(char *map_path, t_data *data);
int				find_path_type(char *s);
void			check_colours(t_data *data, char *s);
mlx_texture_t	*save_texture(char *s);
void			player_checks(t_data *data);
void			wall_check(t_data *data);
// parser/bools.c
bool			validate_mapchars(char **map);
bool			valid_map_border(char *s);
bool			is_mapchar(char c);
bool			is_player(char c);

// window/ - MLX window rendering
void			start_cub(t_data *data);

//src/keys.c
void			cub_keys(mlx_key_data_t key, void *param);
void			resize_screen(int32_t x, int32_t y, void *param);

//src/player_pos.c
void			player_pos(t_cub *cub, t_data *data);

//src/raycast.c
void			render_ray(void	*param);

//src/draw.c
void			draw_ray(int x, t_cub *cub, t_ray *ray);

// src/errors.c
int				cub_error(int err);
int				cub_error_2(int err);

//src/cleaner.c
void			clean_mlx(t_cub *cub);

#endif
