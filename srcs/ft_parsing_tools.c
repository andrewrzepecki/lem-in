/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:43:02 by anrzepec          #+#    #+#             */
/*   Updated: 2019/05/16 19:17:56 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			parse_node(t_graph *g, char **tab, t_node *node, int spec)
{
	if (tab[0][0] == 'L' || ft_strchr(tab[0], '-'))
		return (NODE_ERROR_NAME);
	if (!ft_number_arg(tab[1]) || !ft_number_arg(tab[2]))
		return (NODE_ERROR_CORD);
	if (!(node->name = ft_strdup(tab[0])))
		return (M_FAIL);
	node->x_coord = ft_atoi(tab[1]);
	node->y_coord = ft_atoi(tab[2]);
	node->visited = 0;
	node->special = spec;
	if (spec == 1)
	{
		if (g->start)
			return (START_ERROR);
		g->start = node;
	}
	else if (spec == 2)
	{
		if (g->end)
			return (END_ERROR);
		g->end = node;
	}
	return (1);
}

int			ft_parse_comment(char *s)
{
	ft_putendl(s);
	if (!(ft_strcmp(s, "##start")))
		return (1);
	if (!(ft_strcmp(s, "##end")))
		return (2);
	else
		return (0);
}

int			ft_check_llong(char *s)
{
	int i;
	int	c;

	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '0' && c == 0) || (i == 0 && (s[i] == '-'
						|| s[i] == '+')))
			i++;
		else
		{
			c++;
			i++;
		}
	}
	if (c < 20)
		return (1);
	return (0);
}

int			ft_number_arg(char *s)
{
	long long	d;

	if (!ft_strnum(s) || !ft_strlen(s) || !ft_check_llong(s))
		return (0);
	d = ft_atoll(s);
	if (d > _MAX_INT_ || d < _MIN_INT_)
		return (0);
	return (1);
}
