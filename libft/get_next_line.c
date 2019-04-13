/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:20:17 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/23 17:14:00 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_line(char **line, char **s, int fd, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\0' && s[fd][i] != '\n')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strndup(s[fd], i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

static int		read_line(int fd, char **s, int *ret)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	while ((*ret = read(fd, buff, BUFF_SIZE)))
	{
		if (*ret < 0)
			return (-1);
		buff[*ret] = '\0';
		if (!s[fd])
			s[fd] = (char*)ft_memalloc(1);
		if (!(tmp = ft_strjoin(s[fd], buff)))
			return (-1);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s[FD_SIZE];
	int				ret;
	int				ptr;

	if (BUFF_SIZE < 1 || BUFF_SIZE > MAX_STACK_SIZE)
		return (-1);
	ptr = 0;
	if (fd < 0 || !line)
		return (-1);
	if ((ret = read_line(fd, s, &ptr)) == -1)
		return (ret);
	if (ret == 0 && (!s[fd] || !*s[fd]))
		return (ret);
	return (ft_get_line(line, s, fd, ptr));
}
