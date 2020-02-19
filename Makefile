# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 10:15:06 by bleveque          #+#    #+#              #
#    Updated: 2019/05/16 18:59:11 by bleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INC_PATH = includes/
SRCS_PATH = srcs/
OBJS_PATH = objs/
LIB_PATH = libft/

SRC_NAME = main.c \
			 jenkins_hash.c \
			 error_output.c \
			 parse_links.c \
			 tab_tools.c \
			 push_ants.c \
			 free_node_and_tab.c \
			 ft_parsing_tools.c \
			 create_graph.c \
			 links.c \
			 bfs_samere.c \
			 bfs_add_functions.c \
			 get_paths.c \
			 edmond_karp.c \
			 nb_ants.c \

INC_NAME = lem_in.h
LIB_NAME = libft.a
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

RED = \x1b[31;5;01m
GREEN = \x1b[32;01m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<

all : lib $(NAME) 

lib :
	@printf "Compiling libft ...\r"
	@make -C libft

$(NAME) : $(OBJS) $(LIB) 
	@$(CC) $(LIB) $^ -o $@
	@printf "Compiling lem_in ...\r"
	@echo "$(RED)lem_in$(END)$(GREEN) has compiled ✓✓$(END)"

clean :
	@/bin/rm -f $(OBJS) 
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@cd $(LIB_PATH) ; $(MAKE) fclean 


fclean : clean
	@/bin/rm -f $(NAME) 
	@make fclean -C libft

re : fclean all

.PHONY: all, libft, clean, fclean, re 
