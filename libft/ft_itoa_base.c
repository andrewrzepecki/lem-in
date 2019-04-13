/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:25:58 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/07 17:05:38 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_base(char *base)
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

int		get_int_divlen(unsigned long long int nb, int div)
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

int		add_negative_sign(char **s, int neg)
{
	char *tmp;

	tmp = NULL;
	if (neg)
	{
		if (!(tmp = ft_strjoin("-", *s)))
			return (0);
		ft_strdel(s);
		*s = tmp;
	}
	return (1);
}

char	*ft_set_itoa(unsigned long long nb, char *base, int s_len, int n)
{
	char	*tmp;
	int		res;
	char	*s;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(res = get_base(base)))
		return (NULL);
	s_len = get_int_divlen(nb, res);
	if (!(s = (char*)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	if (!nb)
		s[0] = base[0];
	while (nb)
	{
		s[s_len - i - 1] = base[(unsigned long long int)nb % res];
		nb = nb / res;
		i++;
	}
	s[s_len] = '\0';
	if (!add_negative_sign(&s, n))
		return (NULL);
	return (s);
}

char	*ft_itoa_base(long long int nb, char *base)
{
	int		len;
	char	*s;

	if (!base)
		return (NULL);
	len = 0;
	if (nb >= 0)
	{
		if (!(s = ft_set_itoa(nb, base, len, 0)))
			return (NULL);
	}
	else if (!(s = ft_set_itoa(nb * -1, base, len, 1)))
		return (NULL);
	return (s);
}
