/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:15:06 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 17:24:55 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sign_attrib(char **s, t_flags flags)
{
	char	*tmp;

	if (ft_strchr("Ddi", flags.format) && s[0][0] != '-')
	{
		tmp = *s;
		*s = ft_strchr(flags.attributes, '+') ? ft_strjoin("+", *s)
			: ft_strjoin(" ", *s);
		ft_strdel(&tmp);
	}
	if (*s == NULL)
		return (0);
	return (1);
}

int				ft_hash_attrib(char **s, t_flags flags)
{
	char	*tmp;

	if (ft_strchr("pxXbOo", flags.format) == NULL || (!ft_strcmp(*s, "0")
				&& flags.format != 'p') || (!ft_strlen(*s)
					&& !ft_strchr("Oop", flags.format)))
		return (1);
	tmp = *s;
	if (ft_strchr("xXp", flags.format))
		*s = flags.format == 'X' ? ft_strjoin("0X", *s) : ft_strjoin("0x", *s);
	else if (flags.format == 'b')
		*s = ft_strjoin("0b", *s);
	else
		*s = ft_strjoin("0", *s);
	ft_strdel(&tmp);
	if (*s == NULL)
		return (0);
	return (1);
}

int				ft_apply_attrib(char **s, t_flags flags, int *len)
{
	int	width;

	if ((ft_strchr(flags.attributes, '#') || flags.format == 'p')
			&& !(flags.format == 'o' && (int)ft_strlen(*s) == flags.precision
				&& s[0][0] == '0'))
		if (!ft_hash_attrib(s, flags))
			return (0);
	if (ft_strchr(flags.attributes, '+') || ft_strchr(flags.attributes, ' '))
	{
		if (!ft_sign_attrib(s, flags))
			return (0);
	}
	if ((width = flags.width - ft_strlen(*s) - *len) > 0)
		if (!ft_apply_width(s, flags, width, len))
			return (0);
	return (1);
}
