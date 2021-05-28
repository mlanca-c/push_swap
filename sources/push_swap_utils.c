/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:57:03 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/28 13:43:17 by mlanca-c         ###   ########.fr       */
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
** @param	t_stack	**stack_a	- stack to push minimum value integer to.
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
 * This function will get the fist chunk of stack a the one that needs splitting
 * to b
*/
void	get_chunks(t_stack **stack_a, t_stack **chunks)
{
	int		median;

	median = ft_stack_median(*stack_a);
	ft_stack_add_back(chunks, ft_stack_new(median));
	ft_stack_sort(chunks);
}

/*
** This function splits half of the numbers stored in 'stack_a' to 'stack_b'.
** This function searches for the closest number - whose values are between the
** limits of 'chunks' - of the top of stack_a - either hold_first or
** hold_second, and then chooses which takes less moves to put at the top - if
** hold_first with "ra" or hold_second wih "rra".
** Then the number on top is pushed to stack_b.
**
** @param	t_stack	**stack_a	- stack_a will contain numbers belonging to
** 								stack_b, and others that belong to stack_a.
** @param	t_stack	**stack_b	- stack_b will have numbers that are equal or
** 								less than the median.
** @param	t_stack	**chunks	- stack containing the limits desired by both
** 								stacks
** 									example: 
** 									if the program is sorting 100 numbers, then
** 									chunks will be {min, median, max} which
** 									means stack_a will have the values between
** 									median and max; and stack_b between min and
** 									median inclusive.
*/
void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack **chunks)
{
	int	first;
	int	second;

	first = get_hold_first(*stack_a, *chunks);
	second = get_hold_second(*stack_a, *chunks);
	if (first <= second)
	{
		while (first--)
			rotate_stack(stack_a, 0, "ra\n");
	}
	else
	{
		while (second--)
			reverse_rotate_stack(stack_a, 0, "rra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
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
int	get_hold_first(t_stack *stack_a, t_stack *chunks)
{
	int	first;
	int	max;
	int	min;

	min = chunks->data;
	max = chunks->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data > min && stack_a->data < max)
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
int	get_hold_second(t_stack *stack_a, t_stack *chunks)
{
	int	second;
	int	max;
	int	min;

	stack_a = ft_stack_last(stack_a);
	min = chunks->data;
	max = chunks->next->data;
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
