/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:14:54 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/30 18:17:24 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoll(const char *str)
{
	int			c;
	long long	res;
	int			neg;

	neg = 1;
	res = 0;
	c = 0;
	while (str[c] == '\t' || str[c] == '\n' || str[c] == '\r' || str[c] == '\v'
			|| str[c] == '\f' || str[c] == ' ')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			neg = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = res * 10 + (str[c] - '0');
		c++;
	}
	res *= neg;
	return (res);
}
