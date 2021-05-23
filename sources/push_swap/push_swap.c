/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:17:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/23 23:07:40 by mlanca-c         ###   ########.fr       */
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
** This function takes the string arguments from 'argv'; converts them to
** integers and adds them to the back of the stack - 'stack_a'.
** In order to being added to the back of 'stack_a', the arguments need to be
** only numeric; there can't be two equal arguments, and the integers have to
** respect their limits. If any of these cases happens, the program ends with
** stderr "Error\n".
**
** @param	char	**argv		- command line arguments of main to convert to
** 								inetgers.
** @param	t_stack	*stack_a	- stack to fill in with the converted to integer
** 								command line arguments.
*/
void	move_to_stack(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			exit_push_swap(*stack_a, 0, 0);
		data = ft_atoi(argv[i]);
		if (!ft_isint(data))
			exit_push_swap(*stack_a, 0, 0);
		new_node = ft_stack_new(data);
		if (!new_node)
			exit_push_swap(*stack_a, 0, 0);
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	if (ft_stack_is_duplicate(*stack_a))
		exit_push_swap(*stack_a, 0, 0);
}

/*
 * This function ends the program either if successful or if Error.
 *
 * @param	t_stack	*stack_a	- program's 'stack_a' in case it needs freeing.
 * @param	t_stack	*stack_b	- program's 'stack_b' in case it needs freeing.
 * @param	int		status		- status of program
 * 						0 - In case of crash - end of program with "Error\n"
 * 							caused by a malloc crash; ot in case it's invalid -
 * 							end of program with "Error'n" caused by the command
 * 							line arguments - 'argv' not being valid. stack_a
 * 							needs to be freed.
 * 						1 -	In case of success - end of program without any
 * 							problems. Everything needs to be freed accordingly.
*/
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!status)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
