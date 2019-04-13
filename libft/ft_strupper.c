/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:51:40 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/11 18:00:00 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strupper(char const *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_isalpha(s[i]) && s[i] < 'a')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
