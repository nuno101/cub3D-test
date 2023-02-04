/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:21:07 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/03 20:21:17 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub.h"

/*
 * validate filename ends with ".cub"
 * filename may include a dir: maps/42.cub
 */
int	validate_map_filename(char *filename)
{
	int	i;
	int	len;

	len = ft_strlen(filename);
	i = 0;
	if (len < 4)
		return (1);
	while (filename[i])
	{
		i++;
		if (filename[i] == '.' && filename[i + 1])
		{
			if (!ft_strncmp(filename + i, ".cub", 6) && filename[i - 1] != '/')
				return (0);
		}
	}
	return (1);
}

/*
 * initialise t_data structure
 */
void	init_data(t_data *data)
{
	data->map = NULL;
	data->textures[0] = NULL;
	data->textures[1] = NULL;
	data->textures[2] = NULL;
	data->textures[3] = NULL;
	data->f_colour = 0;
	data->c_colour = 0;
}

/*
 * verify a single map filename is passed as parameter
 * validate map filename is valid by checking open returns a valid fd
 * initialise data
 * call map_data() to fill t_data from filename
 * callign mlx_delete_texture() is optional according to the MLX docs but 
 * is added here to avoid warnings in Linux 
 */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (cub_error(ARG_ERROR));
	if (validate_map_filename(argv[1]))
		return (cub_error(ARG_FILENAME_ERROR));
	if (!ft_ispath(argv[1]))
		exit(cub_error(DIR_ERROR));
	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit(cub_error(MALLOC_ERROR));
	init_data(data);
	parse_map_data(argv[1], data);
	start_cub(data);
	ft_cleansplit(data->map);
	mlx_delete_texture(data->textures[0]);
	mlx_delete_texture(data->textures[1]);
	mlx_delete_texture(data->textures[2]);
	mlx_delete_texture(data->textures[3]);
	free(data);
	printf("Exit cub3d\n");
	return (0);
}
