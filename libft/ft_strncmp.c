/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:20:03 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/11 17:07:58 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (s1[c] && s2[c] && c < n)
	{
		if (s1[c] != s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		c++;
	}
	if (c == n)
		return ((unsigned char)s1[c - 1] - (unsigned char)s2[c - 1]);
	else
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
