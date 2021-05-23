/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:50:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/23 23:04:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h>

/*
** push_swap.c Functions
*/
void	move_to_stack(char **argv, t_stack **stack_a);
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status);

/*
** instructions.c Functions
*/
void	swap_stack(t_stack *mandatory, t_stack *optional, char *message);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message);
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *message);
void	reverse_rotate_stack(t_stack **mandatory,
			t_stack **optional,
			char *message);

/*
** sorting.c Functions
*/
void	get_sorting(t_stack **stack_a, t_stack **stack_b);
void	sorting_small_algorithm(t_stack **stack_a);
void	sorting_medium_algorithm(t_stack **stack_a, t_stack **stack_b);
void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b);

/*
** sorting_utils.c Functions
*/
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);

#endif
