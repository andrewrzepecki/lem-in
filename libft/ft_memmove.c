/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:34:19 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/13 11:22:09 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char*)dst;
	tmp_src = (char*)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len > 0)
		{
			tmp_dst[len - 1] = tmp_src[len - 1];
			len--;
		}
	return (dst);
}
