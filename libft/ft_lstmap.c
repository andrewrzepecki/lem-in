/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:02:56 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/10 17:38:53 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *beg;
	t_list *tmp;

	beg = NULL;
	if (lst && f)
	{
		while (lst)
		{
			new = f(lst);
			if (!beg)
			{
				beg = new;
				tmp = beg;
			}
			else
			{
				tmp->next = new;
				tmp = tmp->next;
			}
			lst = lst->next;
		}
		return (beg);
	}
	return (NULL);
}
