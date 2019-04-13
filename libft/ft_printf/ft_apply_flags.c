/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:09:42 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 17:46:19 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_float_var(va_list ap, t_flags flags)
{
	long double		flt;
	char			*s;

	flt = ft_double_modifier(ap, flags);
	if (flags.precision == -1)
	{
		if (!(s = ft_ftoa(flt, 6)))
			return (NULL);
	}
	else if (!(s = ft_ftoa(flt, flags.precision)))
		return (NULL);
	return (s);
}

char			*ft_char_var(va_list ap, t_flags flags, int *len)
{
	char	*s;

	s = NULL;
	if (!(s = ft_memalloc(2)))
		return (NULL);
	if (flags.format == 'c')
	{
		*s = va_arg(ap, int);
		if (s[0] == 0)
			*len = 1;
	}
	else
		*s = flags.format;
	return (s);
}

char			*ft_str_var(va_list ap, t_flags flags)
{
	char	*s;
	char	*tmp;

	tmp = (char*)va_arg(ap, char *);
	if (!tmp)
	{
		if (!(s = ft_strdup("(null)")))
			return (NULL);
	}
	else if (!(s = ft_strdup(tmp)))
		return (NULL);
	if (!ft_apply_precision(&s, flags))
		return (NULL);
	return (s);
}

char			*ft_numeric_var(va_list ap, t_flags flags)
{
	char					*s;
	unsigned long long int	ud;
	long long int			ld;

	if (ft_strchr("Ddi", flags.format))
	{
		ld = ft_apply_modifier(ap, flags);
		if (!(s = ft_itoa_base(ld, "0123456789")))
			return (NULL);
	}
	else
	{
		ud = ft_apply_umodifier(ap, flags);
		if (!(s = ft_unsigned_value(ud, flags)))
			return (NULL);
	}
	if (!(ft_apply_precision(&s, flags)))
		return (NULL);
	return (s);
}

char			*ft_apply_flags(va_list ap, t_flags flags, int *len)
{
	int		i;
	char	*s;
	t_var	*tab;

	if (!(tab = set_struct_tab()))
		return (NULL);
	if (ft_strchr("DdiOoUuxXpbsf", flags.format) && flags.format)
	{
		i = -1;
		while (++i < 3)
			if (ft_strchr(tab[i].format, flags.format))
				if (!(s = tab[i].f(ap, flags)))
					return (NULL);
	}
	else if (!(s = ft_char_var(ap, flags, len)))
		return (NULL);
	if (!(ft_apply_attrib(&s, flags, len)))
		return (NULL);
	*len += ft_strlen(s);
	if (!flags.format)
		*len = 0;
	free_struct_tab(tab);
	return (s);
}
