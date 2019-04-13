/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:37:23 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/09 16:25:13 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		c;

	c = 0;
	if (!s)
		return (NULL);
	while (s[c])
		c++;
	if (!(str = (char*)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	c = -1;
	while (s[++c])
		str[c] = (*f)(s[c]);
	str[c] = '\0';
	return (str);
}
