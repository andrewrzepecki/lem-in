/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:29 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 18:32:16 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_output(char **buff, va_list ap, int len)
{
	write(1, *buff, len);
	ft_strdel(buff);
	va_end(ap);
}

char			*ft_add_buffsize(char *buff, int *len)
{
	char	*new;

	if (!(new = ft_memalloc(len[RETURN] + len[INDEX] + len[VLEN] + 1)))
		return (NULL);
	ft_memcpy(new, buff, len[RETURN] + 1);
	ft_strdel(&buff);
	buff = NULL;
	return (new);
}

int				ft_write_stdo(char **buff, const char *s, char *v, int *len)
{
	int	i;

	if (*buff == NULL)
	{
		if (!(*buff = ft_memalloc(len[INDEX] + len[VLEN] + 1)))
			return (-1);
	}
	else if (!(*buff = ft_add_buffsize(*buff, len)))
		return (-1);
	i = 0;
	while (i < len[INDEX])
		(*buff)[len[RETURN]++] = s[i++];
	i = 0;
	while (i < len[VLEN])
		(*buff)[len[RETURN]++] = v[i++];
	(*buff)[len[RETURN]] = '\0';
	return (1);
}

char			*ft_get_var(const char *format, va_list ap, int *len)
{
	char			*var;
	t_flags			flags;
	t_get_format	*g_format_tab;

	flags = reset_flags();
	if (!(g_format_tab = set_flag_tab()))
		return (NULL);
	if ((len[POSITION] = ft_format_parser(&flags, format, ap, g_format_tab))
			== -1)
		return (NULL);
	if (!(var = ft_apply_flags(ap, flags, &len[VLEN])))
		return (NULL);
	free_flag_tab(g_format_tab);
	free_current_flags(&flags);
	return (var);
}

int				ft_printf(const char *format, ...)
{
	int		len[4];
	char	*var;
	char	*buff;
	va_list	ap;

	len[RETURN] = 0;
	va_start(ap, format);
	buff = NULL;
	while (format[(len[INDEX] = 0)])
	{
		var = NULL;
		len[VLEN] = 0;
		len[POSITION] = 0;
		while (format[len[INDEX]] != '%' && format[len[INDEX]])
			len[INDEX]++;
		if (format[len[INDEX]] == '%')
			if ((var = ft_get_var(format + len[INDEX], ap, len)) < 0)
				return (-1);
		if (ft_write_stdo(&buff, format, var, len) < 0)
			return (-1);
		format = format + len[INDEX] + len[POSITION];
		ft_strdel(&var);
	}
	ft_printf_output(&buff, ap, len[RETURN]);
	return (len[RETURN]);
}
