# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 16:00:58 by cbinet            #+#    #+#              #
#    Updated: 2017/06/17 13:25:01 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -g

NAME = lem-in

SRC_PATH = srcs/


SRC_NAME = Lemin.c ft_leminsolver.c ft_lemgetenv.c ft_lemindisplays.c \
ft_lemgetrooms.c ft_lemkeepmap.c ft_checkrooms.c

OBJ_PATH = obj/

OBJ_NAME = $(SRC_NAME:c=o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C includes/ft_printf
	@gcc $(FLAG) $^ includes/ft_printf/libftprintf.a -o $(NAME) 
	@echo -n $(NAME)
	@echo " updated !"

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir obj

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc -c $(FLAG) -o $@ -c $<

clean :
	make clean -C includes/ft_printf
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C includes/ft_printf
	rm -f $(NAME)

re: fclean all
