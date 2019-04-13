/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:20:33 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/08 13:24:16 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	c;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	c = -1;
	while (++c < size)
		str[c] = '\0';
	str[c] = '\0';
	return (str);
}
