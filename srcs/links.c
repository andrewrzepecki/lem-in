/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:46:51 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 18:27:49 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_create_link(t_node *parent, t_node *enfant, t_link **opp)
{
	t_link	*link;
	t_link	*tmp;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (M_FAIL);
	link->flow = 0;
	link->child = enfant;
	link->closed = 0;
	link->next = NULL;
	if (!(parent->links))
		parent->links = link;
	else
	{
		tmp = parent->links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = link;
	}
	*opp = link;
	return (1);
}

int		ft_link_link(char **tab, t_graph *graph)
{
	int		hash_0;
	int		hash_1;
	t_link	*l1;
	t_link	*l2;

	l1 = NULL;
	l2 = NULL;
	hash_0 = jenkins_hash(tab[0]);
	hash_1 = jenkins_hash(tab[1]);
	while (ft_strcmp(tab[0], graph->tab[hash_0]->name))
		hash_0 = hash_0 < PRIME ? hash_0 + 1 : 0;
	while (ft_strcmp(tab[1], graph->tab[hash_1]->name))
		hash_1 = hash_1 < PRIME ? hash_1 + 1 : 0;
	if (ft_create_link(graph->tab[hash_0], graph->tab[hash_1], &l1) < 1)
		return (M_FAIL);
	if (ft_create_link(graph->tab[hash_1], graph->tab[hash_0], &l2) < 1)
		return (M_FAIL);
	l1->opposite = l2;
	l2->opposite = l1;
	return (1);
}

int		ft_first_link(t_graph *graph, char **line)
{
	char	**tab;
	int		ret;

	ret = 1;
	if (!(tab = ft_strsplit(*line, '-')))
		return (M_FAIL);
	if (ft_tablen(tab) > 1 && tab[0][0] != '#'
			&& parse_link(graph, tab) == 1)
		ret = ft_link_link(tab, graph);
	else
		ret = LINK_ERROR;
	ft_free_tab(tab);
	ft_putendl(*line);
	ft_strdel(&(*line));
	*line = NULL;
	if (ret < 1)
		return (ret);
	return (ft_links(graph, 0, line));
}

int		ft_links(t_graph *graph, int fd, char **line)
{
	char	**tab;
	int		ret;

	ret = 1;
	while (get_next_line(fd, &(*line)) > 0)
	{
		if (!(tab = ft_strsplit(*line, '-')))
			return (M_FAIL);
		if (ft_tablen(tab) > 0 && tab[0][0] == '#')
			ret = 1;
		else if (ft_tablen(tab) > 1 && tab[0][0] != '#'
				&& parse_link(graph, tab) > 0)
			ret = ft_link_link(tab, graph);
		else
			ret = LINK_ERROR;
		ft_free_tab(tab);
		ft_putendl(*line);
		ft_strdel(&(*line));
		*line = NULL;
		if (ret < 1)
			return (ret);
	}
	return (1);
}
