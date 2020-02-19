/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <bleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:06:21 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 19:42:13 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_max_steps(t_path **tab_paths, int nb_chemins)
{
	int	i;
	int	max_steps;

	i = -1;
	max_steps = tab_paths[0]->len + tab_paths[0]->nb_ants;
	while (++i < nb_chemins)
	{
		if (tab_paths[i]->len + tab_paths[i]->nb_ants > max_steps)
			max_steps = tab_paths[i]->len + tab_paths[i]->nb_ants;
	}
	return (max_steps);
}

int			ft_min_steps(t_path **tab_paths, int nb_chemins)
{
	int	i;
	int	path;
	int	min_steps;

	i = -1;
	min_steps = tab_paths[0]->len + tab_paths[0]->nb_ants;
	path = 0;
	while (++i < nb_chemins)
	{
		if (tab_paths[i]->len + tab_paths[i]->nb_ants < min_steps)
		{
			min_steps = tab_paths[i]->len + tab_paths[i]->nb_ants;
			path = i;
		}
	}
	return (path);
}

/*
** Le but est d'avoir + ou - le meme nombre de steps par chemin (len du chemin +
** nb de fourmis dans ce chemin) dans une strcture a n chemins.
*/

int			number_of_steps(t_path **tab_paths, int nb_chemins, int ants)
{
	int		min_steps;

	if (nb_chemins == 1)
	{
		tab_paths[0]->nb_ants = ants;
		return (tab_paths[0]->nb_ants + tab_paths[0]->len);
	}
	while (ants > 0)
	{
		min_steps = ft_min_steps(tab_paths, nb_chemins);
		tab_paths[min_steps]->nb_ants += 1;
		ants--;
	}
	return (ft_max_steps(tab_paths, nb_chemins));
}

/*
** On va calculer le nombre de steps requis pour chaque combinaison de chemin
** en fonction du nombre de fourmis. Et return la struct Edmond la plus rapide.
*/

t_edmond	*find_best_path(t_graph *graph, t_edmond *edmond)
{
	int			steps;
	int			ants;
	int			tmp_steps;
	int			edmond_nb;
	t_edmond	*tmp;

	ants = graph->ants;
	tmp = edmond;
	tmp_steps = _MAX_INT_;
	while (tmp)
	{
		steps = number_of_steps(tmp->tab_paths, tmp->nb_chemin, ants);
		if (steps < tmp_steps)
		{
			edmond_nb = tmp->nb_chemin;
			tmp_steps = steps;
		}
		tmp = tmp->next;
	}
	tmp = edmond;
	while (tmp->nb_chemin != edmond_nb)
		tmp = tmp->next;
	return (tmp);
}

/*
** Ants in My pants = va lancer toute la machine
*/

void		ants_in_my_pants(t_graph *graph, t_edmond *edmond)
{
	t_edmond	*best_edmond;
	int			steps;

	best_edmond = find_best_path(graph, edmond);
	steps = best_edmond->tab_paths[0]->len + best_edmond->tab_paths[0]->nb_ants;
	ft_push_ants(graph, best_edmond, 0);
	free_edmond(edmond);
}
