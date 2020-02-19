/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:05:49 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 17:47:15 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char x)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	if (s[0] != x && s[0] != '\0')
		c++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == x && s[i] != x && s[i] != '\0')
			c++;
		i++;
	}
	return (c);
}

static int	letters(char const *s, char x, int pos)
{
	int	i;
	int c;
	int k;

	i = 0;
	c = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == x && s[i] != '\0')
			i++;
		while (s[i] != x && s[i] != '\0')
		{
			if ((s[0] != x && pos == 0 && k == 0) || k == pos)
				c++;
			if (s[i + 1] == x)
				k++;
			i++;
		}
	}
	return (c);
}

void		ft_fill(char const *s, char *str, char x, int pos)
{
	int	i;
	int y;
	int	k;

	i = 0;
	y = 0;
	k = 0;
	while (s[y] != '\0')
	{
		while (s[y] == x && s[y] != '\0')
			y++;
		while (s[y] != x && s[y] != '\0')
		{
			if ((s[0] != x && pos == 0 && k == 0) || k == pos)
			{
				str[i] = s[y];
				i++;
			}
			if (s[y + 1] == x)
				k++;
			y++;
		}
	}
	str[i] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	nb_words = words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char*) * (letters(s, c, i) + 1))))
			return (NULL);
		ft_fill(s, tab[i], c, i);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
