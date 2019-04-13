/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:01:07 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/11 16:14:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t c;

	c = 0;
	if (s1 && s2)
	{
		while (s1[c] && s2[c] && c < n)
		{
			if (s1[c] != s2[c])
				return (0);
			c++;
		}
		if (c == n || s1[c] == s2[c])
			return (1);
		else
			return (0);
	}
	return (0);
}
