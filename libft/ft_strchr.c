/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:48:38 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 19:04:41 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		if ((char)c == '\0')
			return ((char*)s + i);
		i = 0;
		while (s[i])
		{
			if (s[i] == (char)c)
				return ((char*)s + i);
			i++;
		}
	}
	return (NULL);
}
