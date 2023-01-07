/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:18:25 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/06 21:41:41 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_buf(char *save, int fd, int *stop)
{
	char	*buf;
	int		count;

	count = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_haschar(save, '\n') && count != 0 && *stop < 1)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < BUFFER_SIZE || count == 0)
		{
			*stop = 1;
			if (count == 0)
			{
				free(buf);
				return (save);
			}
		}
		buf[count] = '\0';
		save = ft_strjoin_dl(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (save[0] == '\n' && save[1] == '\0')
	{
		line[j++] = save[0];
	}
	while (j < i)
	{
		line[j] = save[j];
		j++;
	}
	if (save[j])
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*cut_save(char *str)
{
	char	*new_str;
	int		newline_index;

	newline_index = find_newline(str);
	if (newline_index == -1)
	{
		free(str);
		return (ft_strdup(""));
	}
	new_str = copy_string(str, newline_index + 1);
	free(str);
	return (new_str);
}

char	*get_next_line(int fd, int reset)
{
	char		*line;
	static char	*save;
	static int	stop;

	if (reset == 1)
		stop = 0;
	line = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646 \
	|| stop != 0 || fd > 10240)
		return (NULL);
	if (save == NULL)
		save = ft_strdup("");
	save = read_buf(save, fd, &stop);
	line = get_line(save);
	save = cut_save(save);
	if (ft_haschar(line, '\n'))
		stop = 0;
	return (line);
}

/*
int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("file1", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line[%i] = %s", i + 1, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("no nl gj----------------------\nthis line is \
	(null)?? ---> line[null] = %s", line);
	free(line);
	return (0);
}*/
