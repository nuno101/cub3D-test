/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:45:25 by jjesberg          #+#    #+#             */
/*   Updated: 2022/10/18 05:10:12 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_get_next_str(char **str, char c, int *wordlen)
{
	int	i;

	i = 0;
	*str = *str + *wordlen;
	*wordlen = 0;
	while (**str && **str == c)
	{
		(*str)++;
	}
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return (0);
		(*wordlen)++;
		i++;
	}
	return (0);
}

int	ft_count_words(char const *s, char c)
{
	char	last;
	int		i;
	int		j;

	last = c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (last == c && s[i] != c)
		{
			j++;
		}
		last = s[i];
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	int				next_str_len;
	int				i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!(tab))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < ft_count_words(s, c))
	{
		ft_get_next_str(&next_str, c, &next_str_len);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!(tab[i]))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
