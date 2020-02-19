/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:20:41 by bleveque          #+#    #+#             */
/*   Updated: 2019/02/11 12:13:01 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*minint(int n)
{
	char	*str;
	int		i;

	i = 10;
	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[11] = '\0';
	n = 147483648;
	while (n >= 1)
	{
		str[i] = n % 10 + 48;
		i--;
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = 0;
	if (n == -2147483648)
		return (minint(n));
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	len = ft_len(n) - 1;
	if (!(str = (char*)malloc(sizeof(char) * len + sign + 2)))
		return (NULL);
	str[len + 1 + sign] = '\0';
	str[0] = (n == 0) ? '0' : str[0];
	while (n > 0)
	{
		str[len + sign] = n % 10 + 48;
		len--;
		n = n / 10;
	}
	str[0] = (sign == 1) ? '-' : str[0];
	return (str);
}
