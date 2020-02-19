/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:13:49 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 19:33:00 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*get_path(t_graph *graph, int *parent_map)
{
	int		node;
	int		introduced_by;
	t_path	*path;
	t_path	*tmp;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	node = graph->end->hash;
	path->node = graph->end;
	path->next = NULL;
	while (graph->start->hash != node)
	{
		introduced_by = parent_map[node];
		if (!(tmp = (t_path*)malloc(sizeof(t_path))))
			return (NULL);
		tmp->node = graph->tab[introduced_by];
		tmp->next = path;
		node = introduced_by;
		path = tmp;
	}
	return (path);
}

void	ek_update_flux(t_path *path)
{
	t_node	*next;
	t_link	*link_update;
	t_path	*tmp;

	while (path->next)
	{
		link_update = path->node->links;
		next = path->next->node;
		while (link_update->child != next)
			link_update = link_update->next;
		link_update->flow += 1;
		link_update->opposite->flow -= 1;
		tmp = path;
		path = path->next;
		free(tmp);
	}
	free(path);
}
