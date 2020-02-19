/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:48:39 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 16:43:28 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*copy;
	int		i;
	int		len;

	if (!(s) || !(f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(copy = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		copy[i] = f(s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
