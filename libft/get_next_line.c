/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:18:25 by jjesberg          #+#    #+#             */
/*   Updated: 2022/10/18 07:12:04 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_buf(char *save, int fd, int *stop)
{
	char	*buf;
	int		count;

	count = 1;
	if (save == NULL)
		save = ft_strdup("");
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
		save = ft_strjoin(save, buf);
		if (*stop != 1)
		{
			free(buf);
			buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		}
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

char	*cut_save(char *save)
{
	int		i;
	int		j;
	char	*new;
	int		size;

	i = 0;
	j = 0;
	new = NULL;
	if (!save)
	{
		return (new);
	}
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (new);
	}
	if (save[i] && save[i] == '\n')
	{
		i++;
		size = ft_strlen(save) - i;
		if (size < 0)
			return (new);
		if (size == 0 && save[0] != '\n')
		{
			new = malloc(sizeof(char) * (2));
			new[0] = '\n';
			new[1] = '\0';
			free(save);
			return (new);
		}
		if (size == 0)
		{
			free(save);
			return (NULL);
		}
		new = malloc(sizeof(char) * (size + 1));
		while (save[i] && j < size)
		{
			new[j] = save[i];
			j++;
			i++;
		}
		new[j] = '\0';
	}
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	static int	stop;

	line = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646 \
	|| stop != 0 || fd > 10240)
		return (NULL);
	save = read_buf(save, fd, &stop);
	line = get_line(save);
	save = cut_save(save);
	if (ft_haschar(line, '\n'))
		stop = 0;
	return (line);
}

/*
int main()
{
	char    *line;
	int     fd;
	int     i;

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
	printf("no nl gj----------------------\nthis line is (null)?? ---> line[null] = %s", line);
	free(line);
	return (0);
}*/
