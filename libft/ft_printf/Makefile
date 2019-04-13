# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2019/02/12 16:05:47 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRC 	= 	ft_printf.c \
			ft_format_parser.c \
			ft_apply_flags.c \
			ft_attributes.c \
			ft_struct_settings.c \
			ft_modifier.c \
			ft_precision.c \
			ft_width.c		\
			ft_wildcard.c	\
			ft_tools.c		\
			../ft_strchr.c \
			../ft_strlen.c \
			../ft_strdel.c \
			../ft_memset.c \
			../ft_memcpy.c \
			../ft_memalloc.c \
			../ft_strdup.c \
			../ft_strndup.c \
			../ft_strjoin.c \
			../ft_strcmp.c \
			../ft_strsub.c \
			../ft_atoi.c \
			../ft_ftoa.c \
			../ft_itoa_base.c \
			../ft_uitoa_base.c \
			../ft_fmod.c \
			../ft_floor.c \
			../ft_memdel.c
			
OBJS	=	$(SRC:.c=.o)

CC		=	gcc 

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LIB		=	ar rc

all:		$(NAME)

%.o:		%.c	
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:
			$(RM) $(OBJS) $(NAME)

re:			fclean all

.PHONY: re all fclean clean
