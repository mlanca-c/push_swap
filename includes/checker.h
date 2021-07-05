/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 23:38:08 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/05 22:24:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "utils.h"

/*
** checker.c Functions
*/
void	get_instructions(t_stack **stack_a, t_list **instructions);
int		instruction_is_valid(char *line);
void	implement_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
void	call_instruction(t_stack **stack_a, t_stack **stack_b,
			t_list	*instructions,
			char mode);
void	exit_checker(t_stack *stack_a, t_stack *stack_b, t_list **instructions,
			int status);

/*
** checker_utils.c Functions
*/
void	print_both_stacks(t_stack *stack_a, t_stack *stack_b, char *message);

#endif
