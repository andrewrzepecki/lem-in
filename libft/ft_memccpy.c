/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:50:32 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/08 17:40:10 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			len;
	unsigned char	*t_src;
	unsigned char	*t_dst;

	t_src = (unsigned char*)src;
	t_dst = (unsigned char*)dst;
	len = 0;
	while (len < n)
	{
		if (t_src[len] == (unsigned char)c)
		{
			t_dst[len] = (unsigned char)t_src[len];
			return (dst + (len + 1));
		}
		t_dst[len] = (unsigned char)t_src[len];
		len++;
	}
	return (NULL);
}
