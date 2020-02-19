/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:09:11 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/14 13:06:37 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int	y;
	int check;

	i = 0;
	check = 0;
	y = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char*)s + i);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			check = 1;
			y = i;
		}
		i++;
	}
	if (check == 1)
		return ((char*)s + y);
	return (NULL);
}
