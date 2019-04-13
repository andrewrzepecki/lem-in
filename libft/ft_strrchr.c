/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:30:27 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/07 17:03:55 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;
	int	x;

	x = 0;
	len = 0;
	while (str[len])
		len++;
	while (len > -1)
	{
		if (str[len] == (char)c)
			return ((char*)str + len);
		len--;
	}
	return (NULL);
}
