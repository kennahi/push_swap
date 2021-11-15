# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 13:39:50 by ybouddou          #+#    #+#              #
#    Updated: 2021/06/25 11:40:52 by kennahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
LIB_PATH = Libft
LIB = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	func.c\
		utils.c\
		errors.c\
		check.c\
		sorting.c\
		operations.c\
		cases.c\
		tools.c\

SRC1 = push_swap.c\

OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJ) $(OBJ1) $(LIB)
	@gcc $(OBJ) $(OBJ1) $(LIB_PATH)/$(LIB) -o $(PUSH_SWAP)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@make clean -C $(LIB_PATH)/
	@rm -rf $(OBJ) $(OBJ1)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(PUSH_SWAP)

re: fclean all
