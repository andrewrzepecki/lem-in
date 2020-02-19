/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:00:54 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 16:44:12 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*copy;

	if (!lst)
		return (NULL);
	if (!(copy = f(lst)))
		return (NULL);
	begin = copy;
	while (lst->next)
	{
		lst = lst->next;
		if (!(copy->next = f(lst)))
		{
			free(copy->next);
			return (NULL);
		}
		copy = copy->next;
	}
	return (begin);
}
