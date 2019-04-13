/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:24:14 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/03 17:31:43 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		unsigned_get_base(char *base)
{
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = (char*)ft_memalloc(ft_strlen(base))))
		return (0);
	while (base[i])
	{
		if (ft_strchr(buff, (int)base[i]))
			return (0);
		buff[i] = base[i];
		i++;
	}
	ft_strdel(&buff);
	return (i);
}

static int		unsigned_get_int_divlen(unsigned long long nb, int div)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb = nb / div;
		len++;
	}
	return ((len = len == 0 ? 1 : len));
}

char			*ft_uitoa_base(unsigned long long nb, char *base)
{
	int		i;
	int		c;
	int		res;
	char	*toa;

	if (!base)
		return (NULL);
	if (!(res = unsigned_get_base(base)))
		return (NULL);
	i = unsigned_get_int_divlen(nb, res);
	if (!(toa = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	c = 0;
	if (nb == 0)
		toa[0] = base[0];
	while (nb)
	{
		toa[i - c - 1] = base[nb % res];
		nb = nb / res;
		c++;
	}
	toa[i] = '\0';
	return (toa);
}
