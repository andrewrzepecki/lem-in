/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:27:43 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/09 13:51:04 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*str;
	size_t	c;

	if (!(ptr = (void*)malloc(sizeof(void) * (size))))
		return (NULL);
	str = ptr;
	c = 0;
	while (c < size)
	{
		str[c] = 0;
		c++;
	}
	return (ptr);
}
