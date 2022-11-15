/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:38:38 by jjesberg          #+#    #+#             */
/*   Updated: 2021/10/16 15:02:47 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = 0;
	while (lst != 0)
	{
		if (lst->content != 0)
		{
			tmp = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new, tmp);
		}
		else
			ft_lstclear(&new, del);
		lst = lst->next;
	}
	return (new);
}
