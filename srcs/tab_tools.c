/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <bleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:33:13 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 18:33:36 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			queue_free(t_queue *queue, int **visited)
{
	t_queue *tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
	free(*visited);
	return (M_FAIL);
}

t_queue		*init_queue(t_graph *g)
{
	t_queue	*queue;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	queue->node = g->start;
	queue->next = NULL;
	return (queue);
}

void		reinit_tabs(int *map, int len_map)
{
	int		i;

	i = -1;
	while (++i < len_map)
		map[i] = -1;
}

void		ft_free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}

int			ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
