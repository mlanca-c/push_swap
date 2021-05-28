/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:36:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/28 13:24:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*/
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack **chunks)
{
	ft_stack_remove(chunks);
	get_chunks(stack_b, chunks);
	printf("chunks: ");
	stack_print(*chunks);
	while (contains_above_median(*stack_b, (*chunks)->data))
		split_b_back_to_a(stack_b, stack_a, *chunks);
	printf("stack_a: ");
	stack_print(*stack_a);
	printf("stack_b: ");
	stack_print(*stack_b);
}

/*
*/
void	split_b_back_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *chunks)
{
	int	first;
	int	second;

	first = get_hold_first(*stack_b, &chunks);
	second = get_hold_second(*stack_b, &chunks);
	if (first <= second)
	{
		while (first--)
		{
			if ((*stack_b)->data == ft_stack_min_value(*stack_b))
			{
				push_stack(stack_b, stack_a, "pa\n");
				if (first)
					rotate_stack(stack_a, stack_b, "rr\n");
				else
					rotate_stack(stack_a, 0, "ra\n");
			}
			else
				rotate_stack(stack_b, 0, "rb\n");
		}
	}
	else
	{
		while (second--)
		{
			if ((*stack_b)->data == ft_stack_min_value(*stack_b))
			{
				push_stack(stack_b, stack_a, "pa\n");
				rotate_stack(stack_a, 0, "ra\n");
			}
			else
				reverse_rotate_stack(stack_b, 0, "rrb\n");
		}
	}
	push_stack(stack_b, stack_a, "pa\n");
}

/*
 * This function iterates a stack and checks if its values are all below 'media'
*/
int	contains_above_median(t_stack *stack, int median)
{
	while (stack)
	{
		if (stack->data >= median)
			return (1);
		stack = stack->next;
	}
	return (0);
}
