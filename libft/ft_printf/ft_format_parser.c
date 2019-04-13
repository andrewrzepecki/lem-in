/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:23:21 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 18:21:19 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_attribute_flag(t_flags *flags, char const *format, int *i)
{
	char	*tmp;
	char	*attrib;

	if (!(attrib = ft_strndup(&format[*i], 1)))
		return (-1);
	if (!flags->attributes)
	{
		flags->attributes = attrib;
		attrib = NULL;
	}
	else
	{
		if (!(tmp = ft_strjoin(flags->attributes, attrib)))
			return (-1);
		ft_strdel(&flags->attributes);
		flags->attributes = tmp;
	}
	ft_strdel(&attrib);
	return (0);
}

int				get_modifier_flag(t_flags *flags, char const *format, int *i)
{
	if (flags->modifier && (!ft_strcmp("z", flags->modifier)
				|| !ft_strcmp("j", flags->modifier)))
		return (0);
	if (flags->modifier)
		ft_strdel(&flags->modifier);
	if (format[*i + 1] == format[*i] && format[*i] != 'L')
	{
		if (!(flags->modifier = ft_strsub(format, *i, 2)))
			return (-1);
		(*i)++;
	}
	else
	{
		if (!(flags->modifier = ft_strsub(&format[*i], 0, 1)))
			return (-1);
	}
	return (0);
}

int				get_precision_flag(t_flags *flags, char const *format,
				int *i, va_list ap)
{
	(*i)++;
	if (format[*i] == '*')
		return (ft_precision_wildcard(flags, ap));
	flags->precision = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int				get_width_flag(t_flags *flags, char const *format,
				int *i, va_list ap)
{
	if (format[*i] == '*')
		return (ft_width_wildcard(flags, ap));
	flags->width = ft_atoi(&(format[*i]));
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int				ft_format_parser(t_flags *flags, const char *format, va_list ap,
		t_get_format *g_format_tab)
{
	int				i;
	int				j;

	i = 1;
	while (ft_strchr("*#+-0 .0123456789hlLtjz", format[i]) && format[i])
	{
		j = -1;
		while (++j < 4)
			if (ft_strchr(g_format_tab[j].format, format[i]))
			{
				j = j < 2 ? g_format_tab[j].f(flags, format, &i) :
					g_format_tab[j].fnum(flags, format, &i, ap);
				if (j == -1)
					return (-1);
				break ;
			}
		i++;
	}
	if (format[i])
		flags->format = format[i++];
	return (i);
}
