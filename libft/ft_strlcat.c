/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:13:37 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/09 17:44:07 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t s_size;
	size_t x;

	x = 0;
	s_size = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		x++;
		size--;
	}
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	if (size)
		*dst = '\0';
	return (x + s_size);
}
