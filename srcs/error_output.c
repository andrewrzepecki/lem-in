/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <bleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:23:20 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 19:09:25 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_graph(t_graph *g)
{
	int		i;
	t_link	*tmp;
	t_link	*tracer;

	i = -1;
	while (++i < PRIME)
	{
		if (g->tab[i])
		{
			tracer = g->tab[i]->links;
			while (tracer)
			{
				tmp = tracer;
				tracer = tracer->next;
				free(tmp);
			}
			ft_strdel(&(g->tab[i]->name));
			free(g->tab[i]);
		}
	}
	free(g->tab);
}

int		return_error(int err, t_graph *g)
{
	ft_putendl_fd("ERROR", 2);
	free_graph(g);
	return ((err = 1));
}
