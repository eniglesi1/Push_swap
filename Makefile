# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:58:58 by codespace         #+#    #+#              #
#    Updated: 2023/03/15 14:07:42 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = 	Main.c	Movements.c	Parseo.c	Push_swap.c	Utils.c
OBJS = $(SRC:.c=.o)
LIB = ./printf/libftprintf.a
HEADERS = Push_swap.h
NAME = push_swap
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME):
	@make -C ./printf
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	/bin/rm -f $(OBJS)
	@make clean -C ./printf

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C ./printf
	
re: fclean all
