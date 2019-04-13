/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:08:01 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/08 19:32:33 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			len;

	str = (unsigned char*)s;
	len = 0;
	while (len < n)
	{
		if (*str == (unsigned char)c)
			return ((void*)str);
		str++;
		len++;
	}
	return (NULL);
}
