/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:46:38 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/05 17:25:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function is the program part of the project.
** The main() function will prototype and initialize the two stacks of the
** project - stack_a and stack_b; fill in stack_a with the command line
** arguments; try and sort stack_a; and finally exit the program.
**
** @param	int		argc	- number of command line arguments.
** @param	char	*argv	- executable file plus digits to fill in the stack
** 							and get sorted.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(1);
	stack_a = 0;
	stack_b = 0;
	move_to_stack(&argv[1], &stack_a);
	if (!ft_stack_is_sorted(stack_a))
		get_sorting(&stack_a, &stack_b);
	exit_push_swap(stack_a, stack_b, 1);
	return (0);
}

/*
** This function selects the type of sorting algorithm based in the size of
** 'stack_a'.
** 		if stack's size:
** 		- is less than 3: sort_stack_small() function is called.
** 		- is 4 or 5: sort_stack_medium() function is called.
** 		- is more than 5: sort_stack_big() function is called.
**
** @param	t_stack	**stack_a	- stack that contains the integers to be sorted.
** @param	t_stack	**stack_a	- helper stack, used to help sort stack_a.
*/
void	get_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limits;
	int		maximum;
	int		minimum;

	maximum = ft_stack_max_value(*stack_a);
	minimum = ft_stack_min_value(*stack_a);
	if (ft_stack_size(*stack_a) <= 3)
		sorting_small_algorithm(stack_a);
	else if (ft_stack_size(*stack_a) <= 5)
		sorting_medium_algorithm(stack_a, stack_b);
	else
	{
		limits = ft_stack_new(minimum);
		ft_stack_add_back(&limits, ft_stack_new(maximum));
		sorting_big_algorithm(stack_a, stack_b, &limits, 0);
	}
}

/*
** This function sorts stack_a of size less than 3. Only three types of
** instructions are used: rra, ra, sa.
** @line 99:	in here we check if the second element of stack_a corresponds to
** 				the maximum value of the stack, and if the first one isn't the
** 				minimum value - example: 2 3 1 - Here the solution is simple,
** 				to sort this algorithm we need to reverse rotate the stack.
**
** @line 102:	here we check if the first element of stack_a corresponds to
** 				the minimum value of the stack, and if the second one isn't the
** 				maximum value - example: 3 1 2 - Here the solution is simple,
** 				to sort this algorithm we need to reverse the stack.
**
** @line 105:	if none of the above is the case, we swap the first two elements
** 				of stack_a either to sort it or to then reverse rotate or
** 				rotate - example: 3 2 1 - Here the solution is simple, to sort
** 				this algorithm we swap the first two numbers - 2 3 1 - to then
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
** This function sorts stack_a of size between 4 and 5. The logic behind this
** algorithm is simply divided in three steps:
**
** @line 135,136:	call the push_stack() instructions to push the two smallest
** 					numbers of stack_a to stack_b - for example:
** 					stack_a is 3 2 5 1 4 - we want stack_b to have pushed the
** 					numbers 1 and 2, and stack_a would have: 3 5 4
**
** @line 137:		once stack_a contains only three integers to sort, call
** 					the sorting_small_algorithm() function to sort stack_a.
** 					Following the above example, stack_a would now be: 3 4 5.
**
** @line 139:		finnaly the program only needs to push stack_b's numbers
** 					back to stack_a.
** 					before:
** 						stack_a: 3 4 5
** 						stack_b: 2 1
** 					after:
** 						stack_a: 1 2 3 4 5
** 						stack_b: -
**
*/
void	sorting_medium_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	sorting_small_algorithm(stack_a);
	while (ft_stack_size(*stack_b))
		push_stack(stack_b, stack_a, "pa\n");
}

/*
** This function sorts stacks of size bigger than 5. The logic behind this
** algorithm is a bit more complicated, but I'll try to explain it anyway:
** I decided to separate the algorithm in two different phases: the split phase,
** and the merge phase.
**
** Split Phase:
** 	This phase is focused in pushing to stack_b, the number in between a certain
** 	chunk. The instructions used for this part are "ra", "rra", and "pb". This
** 	phase ends when all the numbers of the chunk are in stack_b.
** 	example:
** 		100 random and unique numbers from 1 to 100.
** 		1st chunk: numbers from 1 to 50 in stack_b.
** 		2nd chunk: numbers from 50 to 100 in stack_a.
**
** Then the program will choose between:
** 	- Merge Back Phase:
** 		This phase occurs if stack_b's size is too big for the Merge Sort Phase.
** 		So what will happen here is that half the values of stack_b will go back
** 		to stack_a - specifically values that are bigger than the median value
** 		of stack_b. This will happen while at the same time trying to sort
** 		what's possible back into stack_a.
**
** 	- Merge Sort Phase:
** 		This phase occurs if stack_b's ready for sorting back into stack_a - has
** 		a few amount of numbers which makes it possible for them to go back
** 		sorted into stack_a.
*/
void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b,
		t_stack **limits, int i)
{
	if (ft_stack_size(*limits) == 1)
	{
		ft_stack_clear(limits);
		return ;
	}
	if (ft_stack_size(*limits) == 2
		&& count_in_between(*stack_a, *limits) >= MAX_SIZE)
		get_new_limit(limits, *stack_a, 1);
	if (!ft_stack_size(*stack_b))
	{
		split_a_to_b(stack_a, stack_b, *limits);
		rotate_until_sorted(stack_a, *limits);
	}
	if (ft_stack_size(*stack_b) >= MAX_SIZE)
		merge_half_to_a(stack_a, stack_b, *limits);
	else
	{
		merge_sort_to_a(stack_a, stack_b, *limits);
		ft_stack_remove(limits);
	}
	sorting_big_algorithm(stack_a, stack_b, limits, ++i);
}
