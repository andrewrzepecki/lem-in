/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:17:50 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/18 17:31:43 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*copy_content;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = (void*)0;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	if (!(copy_content = (void*)malloc(sizeof(size_t) * content_size)))
		return (NULL);
	ft_memcpy(copy_content, content, content_size);
	new->content = copy_content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
