/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:52:03 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/12 12:36:30 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			len;
	unsigned char	*t_src;
	unsigned char	*t_dst;

	t_src = (unsigned char*)src;
	t_dst = (unsigned char*)dst;
	len = 0;
	while (len < n)
	{
		t_dst[len] = t_src[len];
		len++;
	}
	return (dst);
}
