/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:35:57 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/11 17:08:27 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_set_words(char const *str, char **tab, int words, char i)
{
	int c;
	int x;
	int y;

	c = 0;
	x = 0;
	while (str[c] != '\0')
	{
		y = 0;
		while (str[c] == i)
			c++;
		while (str[c] != i && (str[c]))
		{
			tab[x][y] = str[c];
			c++;
			y++;
		}
		if (x < words)
			tab[x][y] = '\0';
		x++;
	}
}

static void		ft_word_length(char const *str, int *ptr, int words, char i)
{
	int c;
	int x;

	x = 0;
	c = 0;
	while (str[c] != '\0')
	{
		if (x < words)
			ptr[x] = 0;
		while (str[c] == i)
			c++;
		while (str[c] != i && (str[c]))
		{
			ptr[x] += 1;
			c++;
		}
		if (x < words)
			ptr[x] += 1;
		x++;
	}
}

static int		ft_word_count(char const *str, char c)
{
	int x;
	int words;
	int a;

	a = 1;
	x = 0;
	words = 0;
	if (str)
	{
		while (str[x])
		{
			if (str[x] == c)
				a = 1;
			if (str[x] != c && (a))
			{
				a = 0;
				words++;
			}
			x++;
		}
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		*ptr;
	int		words;
	int		x;

	words = ft_word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	if (!(ptr = (int*)malloc(sizeof(int) * words)))
		return (NULL);
	if (!words)
	{
		*tab = 0;
		return (tab);
	}
	ft_word_length(s, ptr, words, c);
	x = -1;
	while (++x < words)
		if (!(tab[x] = (char*)malloc(sizeof(char) * ptr[x])))
			return (NULL);
	tab[x] = NULL;
	ft_set_words(s, tab, words, c);
	return (tab);
}
