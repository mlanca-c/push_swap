/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:50:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/01 17:02:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "utils.h"

/*
** push_swap.c Functions
*/
void	get_sorting(t_stack **stack_a, t_stack **stack_b);
void	sorting_small_algorithm(t_stack **stack_a);
void	sorting_medium_algorithm(t_stack **stack_a, t_stack **stack_b);
void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b,
		t_stack **chunks);

/*
** push_swap_utils.c Functions
*/
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	get_chunks(t_stack **stack_a, t_stack **chunks);
int		get_hold_first(t_stack *stack_a, t_stack *chunks);
int		get_hold_second(t_stack *stack_a, t_stack *chunks);
void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack **chunks);

/*
** push_swap_utils1.c Functions
*/
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack **chunks);
void	split_b_ra(t_stack **stack_b, t_stack **stack_a, int first);
void	split_b_rra(t_stack **stack_b, t_stack **stack_a, int second);
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b);
int		ra_closest(t_stack *stack_b, int value);

#endif
