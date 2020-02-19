# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 09:31:26 by bleveque          #+#    #+#              #
#    Updated: 2019/05/09 17:16:57 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

NAME = libft.a

SRCS_NAME = ft_char_count.c \
	  ft_atoll.c \
	  ft_strnum.c \
	  ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstlen.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_power.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_sort_wordtab.c \
	  ft_sqrt.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_itoa_unsigned_base.c\
	  printf_flags.c \
	  printf_float.c \
	  printf_parser.c\
	  printf_restart.c \
	  printf_arg.c \
	  printf_precision.c \
	  printf_width.c \
	  printf_edit_options.c \
	  printf_getvalue.c \
	  printf_reco_options.c \
	  printf_width_bis.c \
	  get_next_line.c \
	  ft_atol.c \

INCLUDES = ./ 

SRCS_PATH = ./
OBJS_PATH = objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))
SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

CC = clang
FLAGS = -Wall -Wextra -Werror

YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m

all : $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c 
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(YELLOW)libft$(END)$(GREEN) has compiled ✓$(END)"

clean :
	@/bin/rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

