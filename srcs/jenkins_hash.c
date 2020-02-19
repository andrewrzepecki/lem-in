/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jenkins_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:33:03 by anrzepec          #+#    #+#             */
/*   Updated: 2019/05/10 15:34:07 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		jenkins_hash(char *name)
{
	int				i;
	unsigned int	hash;

	i = 0;
	hash = 0;
	while (name[i] != '\0')
	{
		hash += name[i++];
		hash += hash << 10;
		hash += hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	hash = hash % PRIME;
	return (hash);
}
