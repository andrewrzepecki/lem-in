/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_samere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:58:43 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 19:32:09 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		update_all(int *map, t_queue *queue, int *v_tab, t_graph *graph)
{
	int		i;
	int		ret;
	t_link	*tmp_l;

	tmp_l = queue->node->links;
	while (tmp_l)
	{
		i = -1;
		ret = 0;
		while (v_tab[++i] != -1)
			if (v_tab[i] == tmp_l->child->hash)
				ret = 1;
		if (!(ret) && !(is_visited(tmp_l, queue->node, map, graph)))
		{
			if (add_to_queue(tmp_l, queue) < 1)
				return (M_FAIL);
			add_to_visited(tmp_l, v_tab);
			map[tmp_l->child->hash] = queue->node->hash;
		}
		tmp_l = tmp_l->next;
	}
	return (1);
}

int		bfs_launcher(t_graph *graph, int *parent_map)
{
	int			*visited;
	t_queue		*queue;
	t_queue		*tmp;
	int			i;

	if (!(visited = (int*)malloc(sizeof(int) * (graph->nb_nodes + 1))))
		return (M_FAIL);
	i = -1;
	while (++i <= graph->nb_nodes)
		visited[i] = -1;
	visited[0] = graph->start->hash;
	queue = init_queue(graph);
	while (queue && queue->node != graph->end)
	{
		if (update_all(parent_map, queue, visited, graph) < 1)
			return (queue_free(queue, &visited));
		tmp = queue;
		queue = queue->next;
		free(tmp);
		tmp = NULL;
	}
	i = queue ? 1 : 0;
	queue_free(queue, &visited);
	return (i);
}

int		init_bfs(t_graph *graph)
{
	int			*parent_map;
	t_edmond	*edmond;
	t_path		*path;
	int			iter;

	if (!(parent_map = (int*)malloc(sizeof(int) * PRIME)))
		return (0);
	reinit_tabs(parent_map, PRIME);
	iter = 0;
	while (bfs_launcher(graph, parent_map))
	{
		if (!(path = get_path(graph, parent_map)))
		{
			free(parent_map);
			return (M_FAIL);
		}
		ek_update_flux(path);
		if (!(edmond = update_edmond(graph, edmond, ++iter)))
			return (M_FAIL);
		reinit_tabs(parent_map, PRIME);
	}
	free(parent_map);
	ants_in_my_pants(graph, edmond);
	return (1);
}
