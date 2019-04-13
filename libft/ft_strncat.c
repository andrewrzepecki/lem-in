/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:09:28 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/06 15:10:23 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		c;
	size_t	len;

	c = 0;
	len = 0;
	while (s1[c])
		c++;
	while (s2[len] && len < n)
	{
		s1[c] = s2[len];
		c++;
		len++;
	}
	s1[c] = '\0';
	return (s1);
}
