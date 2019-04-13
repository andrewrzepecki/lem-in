/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:56:07 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/11 17:59:09 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlower(char const *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_isalpha(s[i]) && s[i] >= 'a')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
