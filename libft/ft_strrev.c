/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:23:44 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/03 12:23:46 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	if (str)
	{
		i = -1;
		j = ft_strlen(str);
		while (++i < --j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
		}
	}
}
