/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:36:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/05 22:26:27 by mlanca-c         ###   ########.fr       */
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

	size = count_in_between(*stack_a, limits);
	while (ft_stack_size(*stack_b) < size)
	{
		first = get_hold_first(*stack_a, limits);
		while (first--)
			rotate_stack(stack_a, 0, "ra\n");
		push_stack(stack_a, stack_b, "pb\n");
	}
}

/*
** This function takes a stack - 'stack_b' - and all its numbers above the
** second element of 'limits' are pushed back to 'stack_a'
** 		example:
** 			50 random numbers between 1 and 50;
** 			stack_a: ]25, 50] unsorted
** 			stack_b: [1, 25] unsorted
** 			limits: {1, 13, 25, 50}
** 		all numbers bigger than 13 have to go back to stack_a.
**
** @param	t_stack	**stack_a	- stack where the numbers will go back to.
** @param	t_stack	**stack_b	- stack where the numbers above the second
** 								element of 'limits' will have to move out of.
** @param	t_stack	*limits		- stack that contains the limits of the
** 								partitions of the other stacks.
*/
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	get_new_limit(&limits, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, limits->next->data))
	{
		if ((*stack_b)->data == ft_stack_min_value(*stack_b))
		{
			push_stack(stack_b, stack_a, "pa\n");
			if ((*stack_b)->data != ft_stack_min_value(*stack_b)
				&& (*stack_b)->data <= limits->next->data)
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data > limits->next->data)
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
}

/*
** This function merges the rest of stack_b' to 'stack_a' in a sorted matter.
**
** @param	t_stack	**stack_a	- stack where the numbers will go back to
** 								sorted.
** @param	t_stack	**stack_b	- stack where the numbers where. At the end
** 								this stack will be empty.
** @param	t_stack	*limits		- stack that contains the limits of the
** 								partitions of the other stacks.
*/
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	t_stack	*duplicate;

	duplicate = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&duplicate);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == duplicate->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			duplicate = duplicate->next;
			 if (ft_stack_size(*stack_b) && (*stack_b)->data != duplicate->data
				&& (*stack_b)->data != ft_stack_max_value(*stack_b))
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data == ft_stack_max_value(*stack_b))
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
	while (ft_stack_last(*stack_a)->data != limits->next->data)
		rotate_stack(stack_a, 0, "ra\n");
	limits->next->data = get_next_value(*stack_a, &limits);
	ft_stack_clear(&duplicate);
}

/*
** This function rotates stack_a until the sorted numbers are found at the
** bottom of the stack sorted in descending order.
**
** @param	t_stack	*stack_a	- stack to sort.
**
** @param	t_stack	**limits	- helper stack to know values of stack_a that
** 								are sorted.
*/
void	rotate_until_sorted(t_stack **stack_a, t_stack *limits)
{
	t_stack	*duplicate;
	int		num;
	int		index;

	duplicate = ft_stack_duplicate(*stack_a);
	ft_stack_add_front(&duplicate, ft_stack_new(limits->data));
	ft_stack_sort(&duplicate);
	num = ft_stack_get(duplicate, ft_stack_find(duplicate, limits->data) - 1);
	ft_stack_clear(&duplicate);
	index = ft_stack_find(*stack_a, num);
	if (num == -2147483648 || index == -2147483648)
		return ;
	if (index <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->data != num)
			rotate_stack(stack_a, 0, "ra\n");
	else
		while (ft_stack_last(*stack_a)->data != num)
			reverse_rotate_stack(stack_a, 0, "rra\n");
}

/*
** This function takes a stack - 'stack_a' and counts its numbers in between the
** first two elements of the stack 'limits'.
**
** @param	t_stack	*stack_a	- stack to count numbers from.
**
** @param	t_stack	**limits	- helper stack to know the limits of stack_a.
** 
** @return
** 		- The count_in_between() function returns the number of elements in
** 		between 'limits's' first two elements that exist in stack_a.
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
	ft_stack_clear(&duplicate);
	return (max_idx - min_idx + 1);
}
