# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 13:11:28 by mlanca-c          #+#    #+#              #
#    Updated: 2021/05/14 12:59:31 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT		=	./libft/libft.a
LIBFT_PATH	=	./libft
SRC			=	sources/push_swap.c
INC			=	-Iincludes -Ilibft
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

ifeq ($(DEBUG), 1)
	D_FLAG 	=	-g
endif

ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=address -g
endif

$(NAME):
	@printf "\e[1;34m\nCompiling libft:\e[0m\n\n"
	@# Compiles Libft
	$(MAKE) -C ./libft

	@# Compile push_swap
	@printf "\e[1;34m\nCompiling push_swap:\e[0m\n\n"
	$(CC) $(CFLAG) $(D_FLAG) $(SRC) $(INC) $(LIBFT) -o $(NAME)

	@printf "\e[0;32m\nCompilation done. push_swap ready.\e[0m\n"

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
