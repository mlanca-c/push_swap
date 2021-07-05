/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:03:16 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/05 17:49:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function pushes the two integers smallest integers from stack_a to
** stack_b.
** The push_min_to_b() function is a helper function of the 
** sorting_medium_algorithm() function. It iterates stack_a searching for its
** minimum value integer by rotating or reverse rotating the stack, and then -
** once the minimum value is at the top - push_stack() function is called to 
** push it to stack_b.
**
** @param	t_stack	**stack_a	- stack to iterate in search of minimum value.
** @param	t_stack	**stack_b	- stack to push minimum value integer to.
*/
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;

	minimum = ft_stack_min_value(*stack_a);
	while ((*stack_a)->data != minimum)
	{
		if ((*stack_a)->data != minimum && (*stack_a)->next->data != minimum)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else
			rotate_stack(stack_a, 0, "ra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
}

/*
** This function will grab the median of 'stack_a' between the first two limits
** of the stack 'limits' and add it to 'limits'.
**
** @line 72-73	The get_new_limit() function starts by creating a duplicated
** 				stack of 'stack_a' - 'duplicate'; and sorting that stack -
** 				'duplicate' will be a sorted version 'stack_a'.
**
** @line 74-75	the function will then try to find the index in duplicate of the
** 				first element of 'limits' - min_idx; the same happens to
** 				'max_idx' - the index of the second element of 'limits' in
** 				'duplicate'.
**
** @line 76		after that it is possible to find the index of the median
** 				element of max_idx and min_idx. The calculations are: 
** 					(max_idx - min_idx) / 2 + min_idx
**
** @line 76		the new will then be the element whose index in duplicate is of
** 				the number in between max_idx and min_idx.
**
** @line 77-78	new is added to limits and limits is sorted so that it contains
** 				all the partitions of stack_a in order.
*/
void	get_new_limit(t_stack **limits, t_stack *stack, int status)
{
	t_stack	*duplicate;
	int		min_idx;
	int		max_idx;
	int		new;

	duplicate = ft_stack_duplicate(stack);
	ft_stack_sort(&duplicate);
	if (status)
	{
		min_idx = ft_stack_find(duplicate, (*limits)->data);
		max_idx = ft_stack_find(duplicate, (*limits)->next->data);
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_stack_get(duplicate, ft_stack_size(duplicate) / 2);
	ft_stack_add_front(limits, ft_stack_new(new));
	ft_stack_sort(limits);
	ft_stack_clear(&duplicate);
}

/*
** This function iterates stack_a, from the top and finds the first number with
** values between the first and the second number in 'chunks'.
**
** @param	t_stack	*stack_a	- This stack will be iterated in order o find
** 								the position of the first number between
** 								'chunks'.
** @param	t_stack	*chunks		- this stack will serve as the limits to find
** 								the number in 'stack_a'.
**
** This function returns the extimated number or "ra" instructions necessary for
** the number found in stack_a to be on top.
*/
int	get_hold_first(t_stack *stack_a, t_stack *limits)
{
	int	first;
	int	max;
	int	min;

	min = limits->data;
	max = limits->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

/*
** This function iterates stack_a, from the bottom and finds the first number
** with values between the first and the second number in 'chunks'.
**
** @param	t_stack	*stack_a	- This stack will be iterated in order o find
** 								the position of the last number between
** 								'chunks'.
** @param	t_stack	*chunks		- this stack will serve as the limits to find
** 								the number in 'stack_a'.
**
** This function returns the extimated number or "rra" instructions necessary
** for the number found in stack_a to be on top.
*/
int	get_hold_second(t_stack *stack_a, t_stack *limits)
{
	int	second;
	int	max;
	int	min;

	stack_a = ft_stack_last(stack_a);
	min = limits->data;
	max = limits->next->data;
	second = 1;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (second);
		second++;
		stack_a = stack_a->previous;
	}
	return (second);
}

/*
** This function is a helper function of merge_sort_to_a() function. It will
** return the minimum number of stack_a that is not sorted, as the new limit.
**
** 		example:
** 			limits: {12, 25, 50, 100}
** 			stack_a: [1, 12] sorted
** 					]12, 100] unsorted
** 			new limits: {13, 25, 50, 100}
**
** @param	t_stack	*stack_a	- stack to get the new limit from.
**
** @param	t_stack	**limits	- stack that contains the old limit.
**
** @return
** 		- the get_next_value() function returns the new limits to be added to
** 		'limits' later in merge_sort_to_a() function.
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
	{
		ft_stack_clear(&duplicate);
		return (minimum);
	}
	else
		minimum = ft_stack_get(duplicate, position + 1);
	ft_stack_clear(&duplicate);
	return (minimum);
}
