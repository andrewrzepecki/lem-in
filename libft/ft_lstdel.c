/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:07:09 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/10 16:08:10 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**tracer;
	t_list	*prev;

	tracer = alst;
	while (*tracer)
	{
		prev = *tracer;
		*tracer = (*tracer)->next;
		del(prev->content, prev->content_size);
		free(prev);
		prev = NULL;
	}
}
