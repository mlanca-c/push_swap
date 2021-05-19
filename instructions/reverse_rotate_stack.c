/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:44:11 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 20:55:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function shifts down all elements of 'stack_a' by 1 - the last element
** becomes the first one.
**
** @param	t_stack	**stack_a	- Stack to reverse rotate.
*/
void	reverse_rotate_stack_a(t_stack **stack_a)
{
	t_stack	*last;
	int		data;

	last = ft_stack_last(*stack_a);
	data = last->data;
	ft_stack_remove(&last);
	ft_stack_add_front(stack_a, ft_stack_new(data));
	ft_putstr_fd("rra\n", 1);
}

/*
** This function shifts down all elements of 'stack_b' by 1 - the last element
** becomes the first one.
**
** @param	t_stack	**stack_b	- Stack to reverse rotate.
*/
void	reverse_rotate_stack_b(t_stack **stack_b)
{
	t_stack	*last;
	int		data;

	last = ft_stack_last(*stack_b);
	data = last->data;
	ft_stack_remove(&last);
	ft_stack_add_front(stack_b, ft_stack_new(data));
	ft_putstr_fd("rrb\n", 1);
}

/*
** This function shifts down all elements of 'stack_a' and 'stack_b' by 1 - the
** last element becomes the first one.
**
** @param	t_stack	**stack_a	- Stack to reverse rotate.
** @param	t_stack	**stack_b	- Stack to reverse rotate.
*/
void	reverse_rotate_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;
	int		data;

	last = ft_stack_last(*stack_a);
	data = last->data;
	ft_stack_remove(&last);
	ft_stack_add_front(stack_a, ft_stack_new(data));
	last = ft_stack_last(*stack_b);
	data = last->data;
	ft_stack_remove(&last);
	ft_stack_add_front(stack_b, ft_stack_new(data));
	ft_putstr_fd("rrr\n", 1);
}
