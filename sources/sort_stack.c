/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:33:23 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/20 23:03:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function selects the type of sorting algorithm based in the size of
** 'stack_a'.
** 		if stack's size:
** 		- less than 3: sort_stack_small() function is called.
** 		- 4 or 5: sort_stack_medium() function is called.
** 		- more than 5: sort_stack_big() function is called.
**
** @param	t_stack	**stack_a	- stack that contains the integers to be sorted.
** @param	t_stack	**stack_a	- helper stack, used to help sort stack_a.
*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) <= 3)
		sort_stack_small(stack_a);
	else if (ft_stack_size(*stack_a) <= 5)
		sort_stack_medium(stack_a, stack_b);
	else
		sort_stack_big(stack_a, stack_b);
}

/*
** This function sorts stack_a of size less than 3. Only three types of
** instructions are used: rra, ra, sa.
** @line 65:	in here we check if the second element of stack_a corresponds to 
** 				the maximum value of the stack, and if the first one isn't the
** 				minimum value - example: 2 3 1 - Here the solution is simple,
** 				to sort this algorithm we need to reverse rotate the stack.
**
** @line 68:	here we check if the first element of stack_a corresponds to
** 				the minimum value of the stack, and if the second one isn't the
** 				maximum value - example: 3 1 2 - Here the solution is simple,
** 				to sort this algorithm we need to reverse the stack.
**
** @line 71:	if none of the above is the case, we swap the first two elements
** 				of stack_a either to sort it or to then reverse rotate or
** 				rotate - example: 3 2 1 - Here the solution is simple, to sort
** 				this algorithm we swap the first two algorithm - 2 3 1 - to then
** 				reverse rotate them - 1 2 3.
** 
*/
void	sorting_small_algorithm(t_stack **stack_a)
{
	int	maximum;
	int	minimum;

	maximum = ft_stack_max_value(*stack_a);
	minimum = ft_stack_min_value(*stack_a);
	while (!ft_stack_is_sorted(*stack_a))
	{
		if ((*stack_a)->data != minimum
			&& (*stack_a)->next->data == maximum)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else if ((*stack_a)->data == maximum
			&& (*stack_a)->next->data == minimum)
			rotate_stack(stack_a, 0, "ra\n");
		else
			swap_stack(*stack_a, 0, "sa\n");
	}
}

/*
 * This function sorts stack_a of size between 4 and 5. The logic behind the
 * algorithm is simply divided in three steps:
 * 		1st step:		call the push_stack() instructions to push the first 
 * 	   @line 93,94		elements of stack_a to stack_b.
 *
 * 		2nd step:		once stack_a contains only three integers to sort, call
 * 		@line 95		the sorting_small_algorithm() function to sort stack_a.
 * 					
 * 		3rd step:		correctly push the integers of stack_b into stack_a, in
 * 		@line			a sorted matter.
 *
 * @line:	Here the algorithm starts its last phase - the third step. This
 * 			one's logic consists of
*/
void	sorting_medium_algorithm(t_stack **stack_a, t_stack **stack_b);
{
	while (ft_stack_size(stack_a) > 3)
		push_stack(stack_a, stack_b, "pb\n");
	sorting_small_algorithm(stack_a);
}

/*
*/
void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b)
