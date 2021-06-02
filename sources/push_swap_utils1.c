/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:36:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/01 17:32:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*/
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack **chunks)
{
	int	first;
	int	second;

	ft_stack_remove(chunks);
	get_chunks(stack_b, chunks);
	while (ft_stack_has_bigger(*stack_b, (*chunks)->data))
	{
		first = get_hold_first(*stack_b, *chunks);
		second = get_hold_second(*stack_b, *chunks);
		if (first <= second)
			while (first--)
				rotate_stack(stack_b, 0, "rb\n");
		else
			while (second--)
				reverse_rotate_stack(stack_b, 0, "rrb\n");
		push_stack(stack_b, stack_a, "pa\n");
	}
}

/*
*/
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*duplicated;
	t_stack	*temporary;
	t_stack	*last_node;

	duplicated = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&duplicated);
	temporary = duplicated;
	last_node = ft_stack_last(duplicated);
	while (ft_stack_size(*stack_b))
	{
		if (ra_closest(*stack_b, duplicated->data))
		{
			while((*stack_b)->data != duplicated->data)
			{
				if ((*stack_b)->data == last_node->data)
				{
					push_stack(stack_b, stack_a, "pa\n");
					last_node = last_node->previous;
				}
				else
					rotate_stack(stack_b, 0, "rb\n");
			}
			push_stack(stack_b, stack_a, "pa\n");
			rotate_stack(stack_a, 0, "ra\n");
		}
		else
		{
			while((*stack_b)->data != duplicated->data)
			{
				if ((*stack_b)->data == last_node->data)
				{
					push_stack(stack_b, stack_a, "pa\n");
					last_node = last_node->previous;
				}
				else
					reverse_rotate_stack(stack_b, 0, "rrb\n");
			}
			push_stack(stack_b, stack_a, "pa\n");
			rotate_stack(stack_a, 0, "ra\n");
		}
		duplicated = duplicated->next;
	}
	ft_stack_clear(&temporary);
}

/*
*/
int	ra_closest(t_stack *stack_b, int value)
{
	int	first;
	int	half;

	first = 0;
	half = ft_stack_size(stack_b) / 2;
	while (stack_b)
	{
		if (stack_b->data == value)
			break ;
		first++;
		stack_b = stack_b->next;
	}
	if (first <= half)
		return (1);
	return (0);
}
