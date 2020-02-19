/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:27:27 by bleveque          #+#    #+#             */
/*   Updated: 2019/05/16 17:07:57 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include "libft.h"

typedef struct		s_save
{
	char			*content;
	int				fd;
	struct s_save	*next;
}					t_save;

int					get_next_line(const int fd, char **line);

#endif
