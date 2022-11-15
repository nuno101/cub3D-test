/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 01:32:06 by jjesberg          #+#    #+#             */
/*   Updated: 2022/10/18 07:08:53 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_digit_base(char c, int base)
{
	if (base <= 10)
		if (c >= '0' && c <= '9')
			return (1);
	if (((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10))))
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, int str_base)
{
	int	dec;
	int	sign;
	int	i;

	if (!str[0] || (str_base < 2 || str_base > 16))
		return (0);
	i = 0;
	sign = 1;
	dec = 0;
	if (str[0] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] != '\0' && is_digit_base(str[i], str_base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			dec = (dec * str_base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			dec = (dec * str_base) + (str[i] - 'a' + 10);
		else
			dec = (dec * str_base) + (str[i] - '0');
		i++;
	}
	return (dec * sign);
}
