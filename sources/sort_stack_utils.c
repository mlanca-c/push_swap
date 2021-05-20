/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:35:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/20 22:18:11 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * This functions stores in a stack the maximum and minimum values of stack.
*/
t_stack	*get_limits(t_stack *stack)
{
	t_stack	*limits;
	
	ft_stack_add_back(&limits, ft_stack_new(ft_stack_max_value(stack)));
	ft_stack_add_back(&limits, ft_stack_new(ft_stack_min_value(stack)));
	return (limits);
}
