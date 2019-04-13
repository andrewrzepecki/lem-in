/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:10:00 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/08 13:11:22 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long 		ft_floor(long double nb)
{
	long long	nbi;

	nbi = (long long)nb;
	return (nb < nbi ? nbi - 1 : nbi);
}
