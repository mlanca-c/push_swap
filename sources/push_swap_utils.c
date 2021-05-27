/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:57:03 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/26 19:59:36 by mlanca-c         ###   ########.fr       */
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
*/
void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack **chunks)
{
	int	first;
	int	second;
	int	size;

	first = get_hold_first(stack_a, chunks);
	second = get_hold_second(stack_a, chunks);
	size = ft_stack_size(*stack_a);
	if (first < ft_stack_size(stack_a) - second)
		rotate_stack(stack_a, 0, "ra\n");
	else
		reverse_rotate_stack(stack_a, 0, "rra\n");	
}

int	get_hold_second(t_stack *stack_a, **t_stack chunks)
{
	int	second;

	stack_a = ft_stack_last(stack_a);
	while (stack_a)
	{
		if ((*chunks)->data >= stack_a->data &&
				(*chunk)->next->data < stack_a->data)
			return (first);
		second++;
		stack_a = stack_a->previous;
	}
}
/*
*/
int	get_hold_first(t_stack *stack_a, **t_stack chunks)
{
	int	first;

	first = 0;
	while (stack_a)
	{
		if ((*chunks)->data >= stack_a->data &&
				(*chunk)->next->data < stack_a->data)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}
