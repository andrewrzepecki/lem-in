/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node_and_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <bleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:41:09 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 18:49:06 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_node_and_tab(char **tab, t_node *node)
{
	free(node);
	ft_free_tab(tab);
}

int		free_node(t_node *node)
{
	free(node);
	return (M_FAIL);
}
