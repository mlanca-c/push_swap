# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 13:11:28 by mlanca-c          #+#    #+#              #
#    Updated: 2021/05/24 17:48:51 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# push_swap (Mandatory) Part Variables #
PS_DIR	=	./sources/push_swap
NAME	=	push_swap
SRC		=	$(PS_DIR)/push_swap.c $(PS_DIR)/instructions.c $(PS_DIR)/sorting.c \
			$(PS_DIR)/sorting_utils.c

	# checker (Bonus) Part Variables #
CHECKER_DIR	=	./sources/checker
CHECKER		=	checker
SRC_B		=	$(CHECKER_DIR)/checker.c

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

all:		$(NAME)
mandatory:	$(NAME)
bonus:		$(CHECKER)

$(NAME):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@printf "$(_INFO) Compiling push_swap ...\n"
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(_SUCCESS) push_swap ready.\n"

$(CHECKER):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@printf "$(_INFO) Compiling checker ...\n"
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_B) $(INC) $(LIBFT) -o $(CHECKER)
	@printf "$(_SUCCESS) checker ready.\n"

clean:
	@ $(RM) $(NAME)
	@printf "$(_INFO) Cleaned all object files in ./push_swap.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

PHONY: all clean fclean re mandatory bonus
