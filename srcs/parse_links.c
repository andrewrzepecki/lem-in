/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <bleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:26:36 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 19:25:27 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		duplicate_link(t_node *node, char *name)
{
	t_link *tracer;

	tracer = node->links;
	while (tracer)
	{
		if (!ft_strcmp(tracer->child->name, name))
			return (0);
		tracer = tracer->next;
	}
	return (1);
}

int		parse_link(t_graph *g, char **tab)
{
	int	i;
	int	link;

	i = 0;
	link = 0;
	if (ft_tablen(tab) != 2)
		return (LINK_ERROR);
	while (i < PRIME + 1)
	{
		if (g->tab[i] && !ft_strcmp(g->tab[i]->name, tab[0])
				&& duplicate_link(g->tab[i], tab[1]))
			link++;
		else if (g->tab[i] && !ft_strcmp(g->tab[i]->name, tab[1]) &&
				duplicate_link(g->tab[i], tab[0]))
			link++;
		i++;
	}
	if (link == 2)
		return (1);
	return (LINK_ERROR);
}
