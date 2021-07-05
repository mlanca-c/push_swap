/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:21:16 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/05 22:38:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** This function is the program part of the bonus of this project - the checker.
** The main() function will prototype and initialize the two stacks of the
** project - 'stack_a' and 'stack_b'; fill in 'stack_a' with the move_to_stack()
** function; get the instructions from the user - get_instructions(); execute
** those instructions - call_instruction() function; and then exit the
** program - exit_checker().
**
** @param	int		argc	- number of command line arguments.
** @param	char	*argv	- executable file plus digits to fill in the stack
** 							and get sorted.
**
** Later on I decided to add a visualizer option to the project. It's possible
** To check what happens with the sorting by compiling the checker part with a
** flag "-v"
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;
	char	mode;

	if (argc == 1 || (argc == 2 && !ft_strcmp("-v", argv[1])))
		exit(1);
	stack_a = 0;
	stack_b = 0;
	instructions = 0;
	mode = 0;
	if (!ft_strcmp("-v", argv[1]))
	{
		move_to_stack(&argv[2], &stack_a);
		mode = 'v';
	}
	else
		move_to_stack(&argv[1], &stack_a);
	get_instructions(&stack_a, &instructions);
	call_instruction(&stack_a, &stack_b, instructions, mode);
	if (ft_stack_is_sorted(stack_a) && !stack_b)
		exit_checker(stack_a, stack_b, &instructions, 2);
	exit_checker(stack_a, stack_b, &instructions, 1);
	return (0);
}

/*
** This function will read a line from STDIN and validate it.
** The get_instructions() will read several lines from STDIN and store them - if
** valid - in instructions (t_list * structure).
**
** @param	t_list	**instructions	- empty list that will be filled with the
** 									instructions to sort stack_a.
** @param	t_stack	**stack_a		- stack that contains the integers to be
** 									sorted.
** @param	t_stack	**stack_b		- helper stack used to help sort stack_a.
*/
void	get_instructions(t_stack **stack_a, t_list **instructions)
{
	char	*line;
	t_list	*new_node;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!(!ft_strcmp("sa", line) || !ft_strcmp("sb", line)
				|| !ft_strcmp("ss", line) || !ft_strcmp("pa", line)
				|| !ft_strcmp("pb", line) || !ft_strcmp("ra", line)
				|| !ft_strcmp("rb", line) || !ft_strcmp("rr", line)
				|| !ft_strcmp("rra", line) || !ft_strcmp("rrb", line)
				|| !ft_strcmp("rrr", line)))
		{
			free(line);
			exit_checker(*stack_a, 0, instructions, 0);
		}
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			exit_checker(*stack_a, 0, instructions, 0);
		}
		ft_lstadd_back(instructions, new_node);
	}
	free(line);
}

/*
** This function will iterate the list 'instructions' and call the
** implement_instruction() function to implement the called instruction.
**
** @param	t_list	*instructions	- list of instructions.
*/
void	call_instruction(t_stack **stack_a, t_stack **stack_b,
			t_list	*instructions, char mode)
{
	if (mode)
		print_both_stacks(*stack_a, *stack_b, "init");
	while (instructions)
	{
		implement_instruction(stack_a, stack_b,
			(char *)instructions->content);
		if (mode)
			print_both_stacks(*stack_a, *stack_b,
				(char *)instructions->content);
		instructions = instructions->next;
	}
}

/*
 * This function implements the given 'instruction' by sending stack_a and
 * stack_b to the corresponding instruction in instructions.c.
 *
** @param	t_stack	**stack_a		- stack that contains the integers to be
** 									sorted.
** @param	t_stack	**stack_b		- helper stack used to help sort stack_a.
 * @param	t_list	*instructions	- list of instructions given by STDIN to
 * 									sort 'stack_a'.
*/
void	implement_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction)
{
	if (!ft_strcmp("sa", instruction))
		swap_stack(*stack_a, 0, 0);
	if (!ft_strcmp("sb", instruction))
		swap_stack(*stack_b, 0, 0);
	if (!ft_strcmp("ss", instruction))
		swap_stack(*stack_a, *stack_b, 0);
	if (!ft_strcmp("pa", instruction))
		push_stack(stack_b, stack_a, 0);
	if (!ft_strcmp("pb", instruction))
		push_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("ra", instruction))
		rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rb", instruction))
		rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rr", instruction))
		rotate_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("rra", instruction))
		reverse_rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rrb", instruction))
		reverse_rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rrr", instruction))
		reverse_rotate_stack(stack_a, stack_b, 0);
}

/*
** This function ends the program either if successful or if Error.
**
** @param	t_stack	*stack_a		- program's 'stack_a' in case it needs
** 									freeing.
** @param	t_stack	*stack_b		- program's 'stack_b' in case it needs
** 									freeing.
** @param	t_list	*instructions	- program's 'instruction' in case it needs
** 									freeing.
** @param	int		status			- status of program
** 						0 - In case the program ended with Errors.
** 						1 - In case the prgram ended with stack_a not being
** 							sorted.
** 						2 - In case the program ended with stack_a being sorted.
*/
void	exit_checker(t_stack *stack_a, t_stack *stack_b, t_list **instructions,
			int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (*instructions)
	{
		while (*instructions)
		{
			free((*instructions)->content);
			ft_lstremove(instructions);
		}
	}
	if (!status)
		ft_putstr_fd("Error\n", 2);
	else if (status == 1)
		ft_putstr_fd("KO\n", 2);
	else if (status == 2)
	{
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
