/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:36:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/08 18:20:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*/
void	get_holds(int *first, int *second, t_stack *stack_a, t_stack *limits)
{
	int		min;
	int		max;
	t_stack	*stack_b;

	min = limits->data;
	max = limits->next->data;
	*first = 0;
	while (stack_a->next)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			break ;
		(*first)++;
		stack_a = stack_a->next;
	}
	stack_b = ft_stack_last(stack_a);
	*second = 1;
	while (stack_b->previous)
	{
		if (stack_b->data >= min && stack_b->data <= max)
			break ;
		(*second)++;
		stack_b = stack_b->previous;
	}
}

/*
 * This function takes a stack - 'stack_b' - and all its numbers above the
 * second element of 'limits' are pushed back to 'stack_a'
 * 		example:
 * 			50 random numbers between 1 and 50;
 * 			stack_a: ]25, 50] unsorted
 * 			stack_b: [1, 25] unsorted
 * 			limits: {1, 13, 25, 50}
 * 		all numbers bigger than 13 have to go back to stack_a.
*/
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	get_new_limit(&limits, *stack_b);
	while (ft_stack_has_bigger(*stack_b, limits->next->data))
	{
		if ((*stack_b)->data == ft_stack_min_value(*stack_b))
		{
			push_stack(stack_b, stack_a, "pa\n");
			rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data > limits->next->data)
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
}

/*
*/
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	t_stack	*first;
	t_stack	*second;

	first = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&first);
	second = ft_stack_last(first);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == first->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			rotate_stack(stack_a, 0, "ra\n");
			first = first->next;
		}
		else if ((*stack_b)->data == second->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			second = second->previous;
		}
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
	while (ft_stack_last(*stack_a)->data != limits->next->data)
		rotate_stack(stack_a, 0, "ra\n");
	limits->next->data = get_next_value(*stack_a, &limits);
}

/*
*/
void	rotate_until_sorted(t_stack **stack_a, t_stack *limits)
{
	while (ft_stack_last(*stack_a)->data != limits->next->data)
		reverse_rotate_stack(stack_a, 0, "rra\n");
}

/*
*/
int	count_in_between(t_stack *stack_a, t_stack *limits)
{
	t_stack	*duplicate;
	int		max_idx;
	int		min_idx;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	min_idx = ft_stack_find(duplicate, limits->data);
	max_idx = ft_stack_find(duplicate, limits->next->data);
	return (max_idx - min_idx + 1);
}

/*
*/
int	get_next_value(t_stack *stack_a, t_stack **limits)
{
	t_stack	*duplicate;
	int		position;
	int		minimum;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	position = ft_stack_find(duplicate, (*limits)->next->data);
	minimum = ft_stack_get(duplicate, position);
	if (minimum == ft_stack_last(duplicate)->data)
		return (minimum);
	else
		minimum = ft_stack_get(duplicate, position + 1);
	return (minimum);
}
