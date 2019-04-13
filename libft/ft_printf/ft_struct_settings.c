/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:16:01 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/08 12:01:34 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_format		*set_flag_tab(void)
{
	t_get_format	*tab;

	if (!(tab = (t_get_format*)malloc(sizeof(t_get_format) * 4)))
		return (NULL);
	if (!(tab[0].format = ft_strdup("#+-0 ")))
		return (NULL);
	tab[0].f = &get_attribute_flag;
	tab[0].fnum = NULL;
	if (!(tab[1].format = ft_strdup("hlLjtz")))
		return (NULL);
	tab[1].f = &get_modifier_flag;
	tab[1].fnum = NULL;
	if (!(tab[2].format = ft_strdup(".")))
		return (NULL);
	tab[2].f = NULL;
	tab[2].fnum = &get_precision_flag;
	if (!(tab[3].format = ft_strdup("*0123456789")))
		return (NULL);
	tab[3].f = NULL;
	tab[3].fnum = &get_width_flag;
	return (tab);
}

void				free_flag_tab(t_get_format *tab)
{
	int	i;

	i = -1;
	while (++i < 4)
		ft_strdel(&(tab[i].format));
	free(tab);
}

t_var				*set_struct_tab(void)
{
	t_var	*tab;

	if (!(tab = (t_var*)malloc(sizeof(t_var) * 3)))
		return (NULL);
	if (!(tab[0].format = ft_strdup("DdiOouUxXpb")))
		return (NULL);
	tab[0].f = &ft_numeric_var;
	if (!(tab[1].format = ft_strdup("s")))
		return (NULL);
	tab[1].f = &ft_str_var;
	if (!(tab[2].format = ft_strdup("f")))
		return (NULL);
	tab[2].f = &ft_float_var;
	return (tab);
}

void				free_struct_tab(t_var *tab)
{
	int	i;

	i = -1;
	while (++i < 3)
		ft_strdel(&(tab[i].format));
	free(tab);
}

t_flags				reset_flags(void)
{
	t_flags	flags;

	flags.attributes = NULL;
	flags.width = 0;
	flags.precision = -1;
	flags.modifier = NULL;
	flags.format = 0;
	return (flags);
}
