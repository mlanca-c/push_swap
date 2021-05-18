/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:31:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/18 20:17:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * status: 2	- One of the command line arguments wasn't a digit.
 * status: 3	- There was a duplicate command line argument.
*/
void	exit_program(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (status == 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Argument is not a digit\n", 1);
	}
	else if (status == 3)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Duplicate number\n", 1);
	}
	exit(1);
}

/*
*/
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

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
	fill_stack(&argv[1], stack_a);
	/*
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	exit_program(stack_a, stack_b);
	*/
	return (0);
}
