/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:27:36 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/11 16:00:14 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		c;
	int		x;

	if (s1 && s2)
	{
		c = ft_strlen(s1);
		c += ft_strlen(s2) + 1;
		if (!(str = (char*)malloc(sizeof(char) * c)))
			return (NULL);
		c = -1;
		while (s1[++c])
			str[c] = s1[c];
		x = -1;
		while (s2[++x])
			str[c++] = s2[x];
		str[c] = '\0';
		return (str);
	}
	return (NULL);
}
