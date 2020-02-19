/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:48:31 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 12:36:36 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ws_beg(char const *s)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	while (s[i] != '\0' && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
	{
		i++;
		c++;
	}
	return (c);
}

static int		ws_end(char const *s)
{
	int	c;
	int	i;

	c = 0;
	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
	{
		c++;
		i--;
	}
	return (c);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;

	if (!(s))
		return ((char*)0);
	len = ft_strlen(s) - ws_beg(s) - ws_end(s);
	i = 0;
	if (ft_strlen(s) == 0 || len < 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
	}
	if (len > 0 && !(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && len > 0)
	{
		str[i] = s[ws_beg(s) + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
