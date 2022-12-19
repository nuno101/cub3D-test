/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:29:11 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 04:57:26 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	find_newline(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

// Returns a copy of 'str' starting at the character at index 'start_index'.
char	*copy_string(char *str, int start_index)
{
	int		i;
	int		size;
	char	*new_str;

	if (str == NULL || start_index < 0)
		return (NULL);
	size = strlen(str) - start_index;
	if (size <= 0)
		return (NULL);
	new_str = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (str[start_index] && i < size)
	{
		new_str[i] = str[start_index];
		i++;
		start_index++;
	}
	new_str[i] = '\0';
	return (new_str);
}
