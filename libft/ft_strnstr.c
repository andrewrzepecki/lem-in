/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:52:53 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/08 20:40:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	c;
	size_t	found;

	if (!ft_strlen(needle))
		return ((char*)haystack);
	c = 0;
	while (haystack[c] && c < len)
	{
		found = 0;
		while (haystack[c + found] == needle[found] && haystack[c + found]
				&& (c + found < len))
			found++;
		if (!needle[found])
			return ((char*)&haystack[c]);
		c++;
	}
	return (NULL);
}
