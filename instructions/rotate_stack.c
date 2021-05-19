/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 20:41:10 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function shifts up all elements of 'stack_a' by 1 - the first element
** becomes the last one.
**
** @param	t_stack	**stack_a	- Stack to rotate.
*/
void	rotate_stack_a(t_stack **stack_a)
{
	int	data;

	data = ft_stack_first(*stack_a)->data;
	ft_stack_remove(stack_a);
	ft_stack_add_back(stack_a, ft_stack_new(data));
	ft_putstr_fd("ra\n", 1);
}

/*
** This function shifts up all elements of 'stack_b' by 1 - the first element
** becomes the last one.
**
** @param	t_stack	**stack_b	- Stack to rotate.
*/
void	rotate_stack_b(t_stack **stack_b)
{
	int	data;

	data = ft_stack_first(*stack_b)->data;
	ft_stack_remove(stack_b);
	ft_stack_add_back(stack_b, ft_stack_new(data));
	ft_putstr_fd("rb\n", 1);
}

/*
** This function shifts up all elements of 'stack_a' and 'stack_b' by 1 - the
** first element becomes the last one.
**
** @param	t_stack	**stack_a	- Stack to rotate.
** @param	t_stack	**stack_b	- Stack to rotate.
*/
void	rotate_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	data;

	data = ft_stack_first(*stack_a)->data;
	ft_stack_remove(stack_a);
	ft_stack_add_back(stack_a, ft_stack_new(data));
	data = ft_stack_first(*stack_b)->data;
	ft_stack_remove(stack_b);
	ft_stack_add_back(stack_b, ft_stack_new(data));
	ft_putstr_fd("rr\n", 1);
}
