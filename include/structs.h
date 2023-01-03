/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/03 19:12:58 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

#define NO 101
#define SO 102
#define WE 103
#define EA 104

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**map;
	char	**map_values;
	int		_split_len;
	int		map_start[2];
	char	*_NO;
	char	*_SO;
	char	*_WE;
	char	*_EA;
	int		F[3];
	int		C[3];
}	t_data;

typedef struct s_cub
{
	t_data		*d;
	void		*mlx;
	int32_t		s_width;
	int32_t		s_height;
	mlx_image_t	*image;
	xpm_t	*xpm;
}	t_cub;

#endif