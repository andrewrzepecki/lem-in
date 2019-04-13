/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:00:32 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/18 11:00:35 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_precision_wildcard(t_flags *flags, va_list ap)
{
	flags->precision = va_arg(ap, int);
	flags->precision = flags->precision < 0 ? -1 : flags->precision;
	return (0);
}

int			ft_width_wildcard(t_flags *flags, va_list ap)
{
	char	*tmp;

	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		if (!flags->attributes)
		{
			if (!(flags->attributes = ft_strdup("-")))
				return (-1);
			flags->width = flags->width * -1;
			return (0);
		}
		tmp = flags->attributes;
		if (!(tmp = ft_strjoin(flags->attributes, "-")))
			return (-1);
		ft_strdel(&flags->attributes);
		flags->attributes = tmp;
		flags->width = flags->width * -1;
	}
	return (0);
}
