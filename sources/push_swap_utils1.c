/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:36:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/09 18:14:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function splits 'stack_a' to 'stack_b' the numbers whose limits are
** between the first two elements of the stack 'limits'.
** 
** @param	t_stack	**stack_a	- Stack to be sorted at the end. At the end of
** 								split_a_to_b() function this stacks will contain
** 								only numbers that are bigger than the second
** 								element of 'limits' or smaller than the first.
**
** @param	t_stack	**stack_b	- Helper stack. At the end of split_a_to_b()
** 								function this stack will contain number between
** 								the first element of 'limits', and the last
** 								element of 'limits'.
**
** @param	t_stack	**limits	- stack containing the limits desired by both
** 								stacks
**
** example: 
** 	- before
** 		limits: {14, 25, 50, 100}
** 		stack_a: [1, 13] sorted
** 				[14, 100] unsorted
** 		stack_b: empty
** 	- after
** 		limits: {14, 25, 50, 100}
** 		stack_a: [1, 13] sorted
** 				]25 , 100] unsorted
** 		stack_b: [14, 25] unsorted
**
*/
void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	int	size;
	int	first;
	int	second;

	size = count_in_between(*stack_a, limits);
	while (ft_stack_size(*stack_b) < size)
	{
		first = get_hold_first(*stack_a, limits);
		second = get_hold_second(*stack_a, limits);
		if (first <= second)
		{
			while (first--)
				rotate_stack(stack_a, 0, "ra\n");
			push_stack(stack_a, stack_b, "pb\n");
		}
		else
		{
			while (second--)
				reverse_rotate_stack(stack_a, 0, "rra\n");
			push_stack(stack_a, stack_b, "pb\n");
		}
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
	get_new_limit_stack_b(&limits, *stack_b);
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
	t_stack	*duplicate;
	int		number;
	int		index;

	duplicate = ft_stack_duplicate(*stack_a);
	ft_stack_add_front(&duplicate, ft_stack_new(limits->data));
	ft_stack_sort(&duplicate);
	number = ft_stack_get(duplicate, ft_stack_find(duplicate, limits->data) - 1);
	index = ft_stack_find(*stack_a, number);
	if (number == -2147483648 || index == -2147483648)
		return ;
	if (index <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->data != number)
			rotate_stack(stack_a, 0, "ra\n");
	else
		while (ft_stack_last(*stack_a)->data != number)
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
