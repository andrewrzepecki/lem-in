/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:24:30 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/08 12:17:15 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				free_current_flags(t_flags *flags)
{
	ft_strdel(&(flags->attributes));
	ft_strdel(&(flags->modifier));
}

void				ft_varchar_free(int nb, ...)
{
	va_list	ap;
	char	**tmp;
	int		i;

	i = -1;
	va_start(ap, nb);
	while (++i < nb)
	{
		tmp = va_arg(ap, char **);
		ft_strdel(tmp);
	}
	va_end(ap);
}

char				*ft_unsigned_value(unsigned long long d, t_flags flags)
{
	char	*s;

	if (flags.format == 'x' || flags.format == 'X' || flags.format == 'p')
		s = flags.format == 'X' ? ft_uitoa_base(d, "0123456789ABCDEF")
			: ft_uitoa_base(d, "0123456789abcdef");
	else if (ft_strchr("Oo", flags.format))
		s = ft_uitoa_base(d, "01234567");
	else
		s = flags.format == 'b' ? ft_uitoa_base(d, "01")
			: ft_uitoa_base(d, "0123456789");
	if (!s)
		return (NULL);
	else
		return (s);
}
