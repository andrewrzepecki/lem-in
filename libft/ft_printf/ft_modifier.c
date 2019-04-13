/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:43:03 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 18:18:57 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_long_umodifier(va_list ap, t_flags flags)
{
	unsigned long long	d;

	if (flags.modifier[0] == 'l')
		d = va_arg(ap, unsigned long int);
	else if (flags.modifier[0] != 'L')
		d = (unsigned short)va_arg(ap, unsigned int);
	else if (flags.format == 'o')
		d = (unsigned char)va_arg(ap, unsigned int);
	else
		d = va_arg(ap, unsigned int);
	return (d);
}

unsigned long long		ft_apply_umodifier(va_list ap, t_flags flags)
{
	unsigned long long int	d;

	d = 0;
	if (!flags.modifier && !ft_strchr("OUp", flags.format))
		d = va_arg(ap, unsigned int);
	else if (ft_strchr("OUp", flags.format))
		d = va_arg(ap, unsigned long long int);
	else if (ft_strlen(flags.modifier) == 2 || ft_strchr(flags.modifier, 'j')
			|| ft_strchr(flags.modifier, 'z'))
	{
		if (flags.modifier[0] == 'l' || ft_strchr(flags.modifier, 'j')
				|| ft_strchr(flags.modifier, 'z'))
			d = va_arg(ap, unsigned long long int);
		else
			d = (unsigned char)va_arg(ap, unsigned long long int);
	}
	else
		d = ft_long_umodifier(ap, flags);
	return (d);
}

long long int			ft_long_modifier(va_list ap, t_flags flags)
{
	long long int	d;

	if (flags.modifier[0] == 'l')
		d = (long)va_arg(ap, long);
	else if (flags.modifier[0] == 'L' && flags.format == 'f')
		d = (long double)va_arg(ap, long double);
	else if (flags.modifier[0] != 'L')
		d = (short)va_arg(ap, int);
	else
		d = va_arg(ap, int);
	return (d);
}

long long int			ft_apply_modifier(va_list ap, t_flags flags)
{
	long long int	d;

	d = 0;
	if (!flags.modifier && flags.format != 'D')
		d = va_arg(ap, int);
	else if (flags.format == 'D' || ft_strlen(flags.modifier) == 2
			|| ft_strchr(flags.modifier, 'j') || ft_strchr(flags.modifier, 'z'))
	{
		if (flags.format == 'D' || flags.modifier[0] == 'l'
				|| ft_strchr(flags.modifier, 'j')
				|| ft_strchr(flags.modifier, 'z'))
			d = va_arg(ap, long long int);
		else
			d = (char)va_arg(ap, int);
	}
	else
		d = ft_long_modifier(ap, flags);
	return (d);
}

long double				ft_double_modifier(va_list ap, t_flags flags)
{
	long double		d;

	if (!flags.modifier || flags.modifier[0] == 'l')
		d = (long double)va_arg(ap, double);
	else
		d = va_arg(ap, long double);
	return (d);
}
