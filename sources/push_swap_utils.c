/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:10:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/26 12:11:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
** This function ends the program either if successful or in case of Error.
**
** @param	t_stack	*stack_a	- program's 'stack_a' in case it needs freeing.
** @param	t_stack	*stack_b	- program's 'stack_b' in case it needs freeing.
** @param	int		status		- status of program
** 						0 - In case of crash - end of program with "Error\n"
** 							caused by a malloc crash; or in case it's invalid -
** 							end of program with "Error'n" caused by the command
** 							line arguments - 'argv' not being valid.
** 							Only stack_a needs to be freed.
** 						1 -	In case of success - end of program without any
** 							problems. Everything needs to be freed accordingly.
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
