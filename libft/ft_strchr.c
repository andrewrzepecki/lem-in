/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:25:25 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/03 12:25:37 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (NULL);
	while (str[len])
	{
		if (str[len] == (char)c)
			return ((char*)str + len);
		len++;
	}
	if (str[len] == c)
		return ((char*)str + len);
	else
		return (NULL);
}
