# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 13:11:28 by mlanca-c          #+#    #+#              #
#    Updated: 2021/05/25 19:52:03 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# push_swap (Mandatory) Part Variables #
NAME		=	push_swap
SRC_A		=	sources/push_swap.c \
				$(SRC_C)

	# common files of mandatory and bonus Variables #
SRC_C		=	sources/instructions.c sources/push_swap_utils.c

	# checker (Bonus) Part Variables #
CHECKER		=	checker
SRC_B		=	sources/checker.c \
				$(SRC_C)

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

	# Includes flag for compilation #
INC		=	-Iincludes -I$(LIBFT_DIR) -I$(LIBFT_DIR)/stack \
			-I$(LIBFT_DIR)/get_next_line

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

mandatory:	$(NAME)
bonus:		$(CHECKER)

$(NAME):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@printf "$(_INFO) Compiling push_swap ...\n"
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_A) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(_SUCCESS) push_swap ready.\n"

all:		$(NAME) $(CHECKER)

$(CHECKER):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@printf "$(_INFO) Compiling checker ...\n"
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_B) $(INC) $(LIBFT) -o $(CHECKER)
	@printf "$(_SUCCESS) checker ready.\n"

clean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)

fclean:
	@ $(RM) $(NAME) $(CHECKER)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@printf "$(_INFO) push_swap and checker.\n"

re: fclean all

PHONY: all clean fclean re mandatory bonus
