/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:49:06 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/13 12:25:03 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stralpha(char const *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_isalpha(s[i]))
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
