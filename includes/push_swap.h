/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:50:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/15 15:40:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "utils.h"

# ifndef MAX_SIZE
#  define MAX_SIZE 20
# endif

/*
** push_swap.c Functions
*/
void	get_sorting(t_stack **stack_a, t_stack **stack_b);
void	sorting_small_algorithm(t_stack **stack_a);
void	sorting_medium_algorithm(t_stack **stack_a, t_stack **stack_b);
void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b,
			t_stack **limits, int i);

/*
** push_swap_utils.c Functions
*/
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	get_new_limit(t_stack **limits, t_stack *stack, int status);
int		get_hold_first(t_stack *stack_a, t_stack *limits);
int		get_hold_second(t_stack *stack_a, t_stack *limits);

/*
** push_swap_utils1.c Functions
*/
void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	rotate_until_sorted(t_stack **stack_a, t_stack *limits);
int		count_in_between(t_stack *stack_a, t_stack *limits);
int		get_next_value(t_stack *stack_a, t_stack **limits);

#endif
