/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/03 19:45:37 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"


static int	screensize(t_cub *m)
{
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	return 0;
}

void	key_press(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	printf("key = %i\n", key.key);
	if (key.key == 256)
	{
		tmp = (t_cub*)param;
		mlx_terminate(tmp->mlx);
		free_data(tmp->d);
		free(tmp);
		mlx_delete_image(tmp->mlx, tmp->image);
		system("leaks cub3D");
		exit(0);
	}

}


void	x_button(void *param)
{
	t_cub	*tmp;

	tmp = (t_cub*)param;
	mlx_terminate(tmp->mlx);
	free_data(tmp->d);
	free(tmp);
	system("leaks cub3D");
	exit(0);
}

/*
static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Try to load the file
	xpm_t* xpm = mlx_load_xpm42("./temp/42.xpm42");
	if (!xpm)
        error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop(mlx);

	// Optional, terminate will clean up any left overs, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_xpm42(xpm);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
*/
int	start_cub(t_data *data)
{
	t_cub	*m;
	m = malloc(sizeof(t_cub));
	m->d = data;
	m->mlx = mlx_init(100, 100, "MLX", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	screensize(m);
	mlx_terminate(m->mlx);
	m->mlx = mlx_init(m->s_width, m->s_height, "Cub3D", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	m->xpm = mlx_load_xpm42("../images/life.xpm"); //error?!?
	if (!m->xpm)
		return (ARG_ERROR);
	m->image = mlx_texture_to_image(m->mlx, &m->xpm->texture);
	if (!m->image)
		return (MALLOC_ERROR);
	if (mlx_image_to_window(m->mlx, m->image, 0, 0) < 0)
        return (error(MALLOC_ERROR));
	//m->image = mlx_new_image(m->mlx, m->s_width, m->s_height);
	//ft_memset(m->image->pixels, 255, m->s_width * m->s_height * 4);
	mlx_key_hook(m->mlx, &key_press, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	free(m);
	return (0);
}