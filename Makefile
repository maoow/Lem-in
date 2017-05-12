# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 16:00:58 by cbinet            #+#    #+#              #
#    Updated: 2017/05/12 15:42:03 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -g

NAME = lem-in

SRC_PATH = srcs/


SRC_NAME = Lemin.c ft_leminsolver.c ft_lemgetenv.c ft_lemindisplays.c \
ft_lemgetrooms.c ft_lemkeepmap.c

OBJ_PATH = obj/

OBJ_NAME = $(SRC_NAME:c=o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAG) $^ includes/ft_printf/libftprintf.a -o $(NAME) 
	@echo -n $(NAME)
	@echo " updated !"

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir obj

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc -c $(FLAG) -o $@ -c $<

clean :
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
