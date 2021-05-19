/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:19:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 20:02:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function swaps the first 2 elements at the top of stack a.
**
** @param	t_stack	*stack_a	- stack to swap at.
*/
void	swap_stack_a(t_stack *stack_a)
{
	ft_swap(&(stack_a->data), &(stack_a->next->data));
	ft_putstr_fd("sa\n", 1);
}

/*
** This function swaps the first 2 elements at the top of stack b.
**
** @param	t_stack	*stack_b	- stack to swap at.
*/
void	swap_stack_b(t_stack *stack_b)
{
	ft_swap(&(stack_b->data), &(stack_b->next->data));
	ft_putstr_fd("sb\n", 1);
}

/*
** This function swaps the first 2 elements at the top of stack a and b.
**
** @param	t_stack	*stack_a	- stack to swap at.
** @param	t_stack	*stack_b	- stack to swap at.
*/
void	swap_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(&(stack_a->data), &(stack_a->next->data));
	ft_swap(&(stack_b->data), &(stack_b->next->data));
	ft_putstr_fd("ss\n", 1);
}
