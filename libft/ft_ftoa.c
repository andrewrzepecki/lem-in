/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:19:07 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 16:27:43 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_fjoin(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	if (ft_strlen(s2))
	{
		if (!(tmp = ft_strjoin(s1, ".")))
			return (NULL);
		ft_strdel(&s1);
		if (!(res = ft_strjoin(tmp, s2)))
			return (NULL);
		ft_strdel(&s2);
		ft_strdel(&tmp);
		return (res);
	}
	ft_strdel(&s2);
	return (s1);
}

char		*set_left(long double nb, long double ent, int len, char *num)
{
	char		*tmp;
	char		*s;

	if (!(s = ft_memalloc(1)))
		return (NULL);
	while (len--)
	{
		num[0] = (int)nb + '0';
		tmp = s;
		if (!(s = ft_strjoin(s, num)))
			return (NULL);
		ft_strdel(&tmp);
		nb = (nb * 10) - ((int)nb * 10);
	}
	if (ent < 0)
	{
		tmp = s;
		if (!(s = ft_strjoin("-", s)))
			return (NULL);
		ft_strdel(&tmp);
	}
	return (s);
}

char		*ft_floating_left(long double nb, long double ent, int precision)
{
	int		i;
	char	*s;
	char	num[2];

	i = 1;
	num[1] = '\0';
	if (!precision && ent > nb && ent)
		nb++;
	ent = nb;
	nb = nb < 0 ? -nb : nb;
	while (nb > 10)
	{
		nb = nb / 10;
		i++;
	}
	if (!(s = set_left(nb, ent, i, num)))
		return (NULL);
	return (s);
}

char		*ft_floating_right(long double mod, int precision)
{
	int		i;
	char	*s;
	char	num[2];
	char	*tmp;

	i = 0;
	if (!(s = ft_memalloc(1)))
		return (NULL);
	mod = (mod < 0) ? mod * -1 : mod;
	num[1] = '\0';
	while (i++ < precision)
	{
		mod = ft_fmod(mod * 10, 10);
		if (i == precision)
			mod = (long long)mod % 10 >= 5 ? mod + 1 : mod;
		num[0] = (int)mod + '0';
		tmp = s;
		if (!(s = ft_strjoin(s, num)))
			return (NULL);
		ft_strdel(&tmp);
	}
	return (s);
}

char		*ft_ftoa(long double nb, int precision)
{
	char		*left;
	char		*right;
	long double	ent;
	long double	mod;

	mod = ft_fmod(nb, 1);
	ent = nb - mod;
	if (!mod)
	{
		if (!(right = ft_memalloc(precision + 1)))
			return (NULL);
		right = (char*)ft_memset(right, '0', (size_t)precision);
	}
	else if (!(right = ft_floating_right(mod, precision)))
		return (NULL);
	if (!precision && ent > nb && ent != 0)
		ent++;
	if (!(left = ft_floating_left(nb, ent, precision)))
		return (NULL);
	return (ft_fjoin(left, right));
}
