/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:10:36 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/06 15:11:36 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	c;

	c = 0;
	while (src[c] && c < len)
	{
		dst[c] = src[c];
		c++;
	}
	while (c < len)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
