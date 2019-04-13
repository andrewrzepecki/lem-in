/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:19:55 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/09 16:27:28 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		c;

	c = 0;
	if (s && f)
	{
		while (s[c])
			c++;
		if (!(str = (char*)malloc(sizeof(char) * (c + 1))))
			return (NULL);
		c = -1;
		while (s[++c])
			str[c] = (*f)(c, s[c]);
		str[c] = '\0';
		return (str);
	}
	return (NULL);
}
