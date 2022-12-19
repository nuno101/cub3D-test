/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:12 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 03:22:43 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

/*save map in struct(data.map) via get_next_line*/
int	init_map(int argc, char **argv, t_data *data)
{
	int fd;
	int i;

	if (argc < 2)
		return (ARG_ERROR);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	data->argc = argc;
	data->argv = argv;
	data->map = malloc(sizeof(char *) * (80));
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
		{
			data->map[i] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}
