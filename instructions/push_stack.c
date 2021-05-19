/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:49:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 20:06:11 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function takes the first element at the top of 'stack_b' and puts it at
** the top of 'stack_a'.
** The push_stack_a() function does nothing if 'stack_b' is empty.
**
** @param	t_stack	**stack_a	- stack where the integer is suppose to go.
** @param	t_stack	**stack_b	- stack to take the integer from.
*/
void	push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b))
		return ;
	ft_stack_add_front(stack_a, ft_stack_new((*stack_b)->data));
	ft_stack_remove(stack_b);
	ft_putstr_fd("pa\n", 1);
}

/*
** This function takes the first element at the top of 'stack_a' and puts it at
** the top of 'stack_b'.
** The push_stack_b() function does nothing if 'stack_a' is empty.
**
** @param	t_stack	*stack_b	- stack where the integer is suppose to go.
** @param	t_stack	*stack_a	- stack to take the integer from.
*/
void	push_stack_b(t_stack **stack_b, t_stack **stack_a)
{
	if (!(*stack_a))
		return ;
	ft_stack_add_front(stack_b, ft_stack_new((*stack_a)->data));
	ft_stack_remove(stack_a);
	ft_putstr_fd("pb\n", 1);
}
