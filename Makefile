# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 13:11:28 by mlanca-c          #+#    #+#              #
#    Updated: 2021/05/18 19:28:09 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# File Name Variables #
NAME		=	push_swap
SRC			=	sources/push_swap.c
INC			=	-Iincludes -Ilibft

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_PATH	=	./libft


	# Compiling Variables #
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
CLIB	=	ar -rc
RM		=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

	# Debugger #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

	# Fsanitize #
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=address -g
endif

$(NAME):
	$(MAKE) -C ./libft
	$(MAKE) stack -C ./libft
	@printf "$(_INFO) Compiling ./push_swap ...\n"
	$(CC) $(CFLAG) $(D_FLAG) $(SRC) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(_SUCCESS) Compilation complete.\n"
	@printf "$(_SUCCESS) push_swap ready.\n"

all: $(NAME)

clean:
	$(RM) $(NAME)
	@printf "$(_SUCCESS) Cleaned all object files in ./push_swap.\n"

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
