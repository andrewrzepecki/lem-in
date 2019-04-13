/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:54:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 16:23:22 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_add_prefix(char **s, char *prefix)
{
	char	*tmp;

	tmp = *s;
	if (!(*s = ft_strjoin(prefix, *s)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

int			ft_move_prefix(char **s, char *prefix, t_flags flags)
{
	char	*del;
	char	*tmp;

	if (ft_strchr(flags.attributes, '0') && ((ft_strchr(flags.attributes, '#')
		&& ft_strchr("OoxXb", flags.format) && !(ft_strlen(*s) == 1
			&& s[0][0] == '0')) || flags.format == 'p'
			|| (ft_strchr("+- ", s[0][0]) && ft_strchr("Ddif", flags.format)))
			&& !(ft_strchr("diOouUxXbp", flags.format)
			&& flags.precision < flags.width && flags.precision != -1))
	{
		tmp = ft_strchr("Xxbp", flags.format) ?
			ft_strsub(*s, 2, ft_strlen(*s) - 2)
			: ft_strsub(*s, 1, ft_strlen(*s) - 1);
		if (!tmp || !(del = ft_strjoin(prefix, tmp)))
			return (0);
		ft_strdel(&tmp);
		tmp = ft_strchr("Xxbp", flags.format) ? ft_strndup(*s, 2)
			: ft_strndup(*s, 1);
		ft_strdel(&(*s));
		if (!tmp || !(*s = ft_strjoin(tmp, del)))
			return (0);
		ft_varchar_free(2, &tmp, &del);
		return (1);
	}
	return (ft_add_prefix(s, prefix));
}

int			ft_invert_prefix(char **s, char *prefix, t_flags flags, int *len)
{
	char	*tmp;

	tmp = *s;
	if (ft_strchr(flags.attributes, '-'))
	{
		if (flags.format == 'c' && *s && s[0][0] == '\0')
		{
			if (!(*s = ft_memalloc(ft_strlen(prefix) + 2)))
				return (0);
			ft_memcpy(*s + 1, prefix, ft_strlen(prefix));
			*len += ft_strlen(prefix);
		}
		else if (!(*s = ft_strjoin(*s, prefix)))
			return (0);
		ft_strdel(&tmp);
		return (1);
	}
	return (ft_move_prefix(s, prefix, flags));
}

int			ft_apply_width(char **s, t_flags flags, int width, int *len)
{
	char	prefix[width + 1];

	ft_memset(prefix, ' ', width);
	prefix[width] = '\0';
	if (ft_strchr(flags.attributes, '0') && !ft_strchr(flags.attributes, '-')
			&& (!(ft_strchr("diOouUxXbpf", flags.format) && flags.precision <\
				flags.width && flags.precision != -1) || flags.format == 'f'))
		ft_memset(prefix, '0', width);
	return (ft_invert_prefix(s, prefix, flags, len));
}
