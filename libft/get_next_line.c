/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:22:39 by bleveque          #+#    #+#             */
/*   Updated: 2019/04/22 11:29:58 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_save	*file_init(const int fd, t_save **file)
{
	t_save	*current;

	current = *file;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (!(current = (t_save*)malloc(sizeof(t_save))))
		return (NULL);
	if (!(current->content = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	current->content[0] = '\0';
	current->fd = fd;
	current->next = *file;
	*file = current;
	return (current);
}

static int		ft_copy_line(char **line, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[j] != '\n' && tmp[j] != '\0')
		j++;
	if (!(line[0] = (char*)malloc(sizeof(char) * j + 1)))
		return (0);
	line[0][j] = '\0';
	while (i < j)
	{
		line[0][i] = tmp[i];
		i++;
	}
	return (1);
}

static int		ft_copy_check(char **line, t_save *current, char *buff)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_strjoin(current->content, buff)))
		return (0);
	ft_strdel(&(current->content));
	if (ft_strchr(buff, 10))
	{
		if (!(ft_copy_line(line, tmp)))
			return (0);
		if (!(current->content = ft_strdup(ft_strchr(tmp, 10) + 1)))
			return (0);
		free(tmp);
		return (2);
	}
	if (!(current->content = ft_strdup(tmp)))
		return (0);
	free(tmp);
	return (1);
}

static int		ft_end(char **line, t_save *current)
{
	char	*tmp;

	ft_copy_line(line, current->content);
	if (ft_strchr(current->content, 10))
	{
		if (!(tmp = ft_strdup(ft_strchr(current->content, 10) + 1)))
			return (-1);
		ft_strdel(&(current->content));
		if (!(current->content = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	else
	{
		ft_strdel(&(current->content));
		return (-1);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_save	*file;
	t_save			*current;
	char			buff[BUFF_SIZE + 1];
	int				rd;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0 ||
		!(current = file_init(fd, &file)))
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		ret = ft_copy_check(line, current, buff);
		if (ret == 2)
			return (1);
		if (ret == 0)
			return (-1);
	}
	if ((current->content) && current->content[0] != '\0')
		return (ft_end(line, current));
	free(current->content);
	free(current);
	return (0);
}
