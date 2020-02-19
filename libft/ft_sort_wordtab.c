/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:26:53 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 12:01:16 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_wordtab(char **tab, size_t n)
{
	size_t	i;
	char	*buffer;

	if (!tab || !n)
		return ;
	i = 0;
	while (i <= n - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			buffer = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buffer;
			i = -1;
		}
		i++;
	}
}
