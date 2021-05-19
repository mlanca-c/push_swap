/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:31:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 17:44:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*/
void	exit_program(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!status)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*
*/
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stack_size(stack_a) >= 3)
		sort_small(stack_a);
	else if (ft_stack_size(stack_a) >= 5)
		sort_medium(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

/*
** This function is the program part of the project.
** The main() function will prototype and initialize the tow stacks of the
** project - stack_a and stack_b. It will also try to fill in stack_a with the
** command line arguments. The sort_stack() function will be called to sort
** stack_a.
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
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&argv[1], &stack_a);
	if (!ft_stack_is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	exit_program(stack_a, stack_b, 1);
	return (0);
}
