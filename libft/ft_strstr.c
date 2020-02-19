/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:22:16 by bleveque          #+#    #+#             */
/*   Updated: 2019/02/07 17:23:59 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			c = 0;
			while (haystack[i + c] == needle[c])
			{
				if (needle[c + 1] == '\0')
					return ((char*)haystack + i);
				c++;
			}
		}
		i++;
	}
	return (NULL);
}
