/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:22:33 by anrzepec          #+#    #+#             */
/*   Updated: 2019/05/16 19:12:50 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_path **tab, int len)
{
	int		i;
	t_path	*path;
	t_path	*tmp;

	i = 0;
	while (i < len)
	{
		path = tab[i];
		while (path)
		{
			tmp = path;
			path = path->next;
			free(tmp);
		}
		i++;
	}
	free(tab);
}

void	free_edmond(t_edmond *edmond)
{
	t_edmond	*tmp;

	while (edmond)
	{
		tmp = edmond;
		free_paths(edmond->tab_paths, edmond->nb_chemin);
		edmond = edmond->next;
		free(tmp);
	}
}

int		valid_graph(t_graph *g)
{
	int	*map;

	if (!g->start || !g->end)
		return (NO_IO);
	if (!(map = (int*)malloc(sizeof(int) * PRIME)))
		return (M_FAIL);
	reinit_tabs(map, PRIME);
	if (bfs_launcher(g, map) == 1)
	{
		ft_putendl("");
		free(map);
		return (1);
	}
	free(map);
	return (0);
}

int		main(void)
{
	int			ret;
	t_graph		graph;

	if ((ret = init_graph(&graph)) < 0)
		return (return_error(ret, &graph));
	if (!ret)
	{
		ft_putstr_fd("Stopped processing links after an error. ", 2);
		ft_putendl_fd("Solving lem-in anyway ...", 2);
	}
	if ((ret = valid_graph(&graph)) < 1)
		return (return_error(ret, &graph));
	init_bfs(&graph);
	free_graph(&graph);
	return (0);
}
