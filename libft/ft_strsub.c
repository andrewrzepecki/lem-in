/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:47:13 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/09 16:03:36 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	c;

	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		c = 0;
		while (c < len)
		{
			str[c] = s[start];
			start++;
			c++;
		}
		str[c] = '\0';
		return (str);
	}
	else
		return (NULL);
}
