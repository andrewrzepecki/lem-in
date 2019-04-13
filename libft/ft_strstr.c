/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:28:17 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/08 21:37:43 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t	c;
	size_t	found;

	if (!ft_strlen(needle))
		return ((char*)haystack);
	c = 0;
	while (haystack[c])
	{
		found = 0;
		while (haystack[c + found] == needle[found] &&
				needle[found] && haystack[c + found])
			found++;
		if (needle[found] == '\0')
			return ((char*)&haystack[c]);
		c++;
	}
	return (0);
}
