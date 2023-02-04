/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:23:03 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/04 10:19:00 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * find texture code
 */
int	get_texture_code(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, "NO ", 3))
			return (NO);
		else if (!ft_strncmp(s + i, "SO ", 3))
			return (SO);
		else if (!ft_strncmp(s + i, "EA ", 3))
			return (EA);
		else if (!ft_strncmp(s + i, "WE ", 3))
			return (WE);
		i++;
	}
	return (NONE);
}

/*
 * parse_raw_data helper funtion to stay below 25 lines and comply
 * with the norm
 */
int	add_tex_code(int tex_code)
{
	if (tex_code == NONE)
		return (0);
	if (tex_code == NO)
		return (4);
	else
		return (tex_code);
}

/*
 * read line from i=3 since the first 3 characters have been validated
 * 
 */
mlx_texture_t	*save_texture(char *s)
{
	mlx_texture_t	*texture;
	int				i;

	i = 3;
	texture = NULL;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			if (!ft_ispath(s + i))
				exit(cub_error(TEX_PATH_ERROR));
			else
			{
				texture = mlx_load_png(s + i);
				if (!texture)
					exit(cub_error(TEX_MLX_LOAD_PNG_ERROR));
				break ;
			}
		}
		i++;
	}
	return (texture);
}
