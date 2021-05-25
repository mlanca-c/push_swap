/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:39:52 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/25 18:41:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** This function is the program part of the bonus of this project - checker.
** The main() function will prototype and initialize the two stacks of the
** project - 'stack_a' and 'stack_b'; fill in 'stack_a' with the move_to_stack()
** function; get the instructions from the user - get_instructions(); execute
** those instructions - implement_instructions() function; and then exit the
** program - exit_checker().
**
** @param	int		argc	- number of command line arguments.
** @param	char	*argv	- executable file plus digits to fill in the stack
** 							and get sorted.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	if (argc == 1)
		exit(1);
	stack_a = 0;
	stack_b = 0;
	instructions = 0;
	move_to_stack(&argv[1], &stack_a);
	get_instructions(&stack_a, &instructions);
	implement_instructions(&stack_a, &stack_b, instructions);
	if (ft_stack_is_sorted(stack_a) && !stack_b)
		exit_checker(stack_a, stack_b, instructions, 2);
	exit_checker(stack_a, stack_b, instructions, 1);
	return (0);
}

/*
*/
void	get_instructions(t_stack **stack_a, t_list **instructions)
{
	char	*line;
	t_list	*new_node;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!instruction_is_valid(line))
		{
			free (line);
			exit_checker(*stack_a, 0, *instructions, 0);
		}
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			exit_checker(*stack_a, 0, *instructions, 0);
		}
		ft_lstadd_back(instructions, new_node);
	}
	free(line);
}

/*
 * This function implements the given instructions by sending stack_a and
 * stack_b to the corresponding instructions.
 *
 * @param	t_stack	**stack_a		-
 * @param	t_stack	**stack_b		-
 * @param	t_list	*instructions	-
*/
void	implement_instructions(t_stack **stack_a, t_stack **stack_b,
			t_list *instructions)
{
	while (instructions)
	{
		if (!ft_strcmp("sa", instructions->content))
			swap_stack(*stack_a, 0, 0);
		if (!ft_strcmp("sb", instructions->content))
			swap_stack(*stack_b, 0, 0);
		if (!ft_strcmp("ss", instructions->content))
			swap_stack(*stack_a, *stack_b, 0);
		if (!ft_strcmp("pa", instructions->content))
			push_stack(stack_b, stack_a, 0);
		if (!ft_strcmp("pb", instructions->content))
			push_stack(stack_a, stack_b, 0);
		if (!ft_strcmp("ra", instructions->content))
			rotate_stack(stack_a, 0, 0);
		if (!ft_strcmp("rb", instructions->content))
			rotate_stack(stack_b, 0, 0);
		if (!ft_strcmp("rr", instructions->content))
			rotate_stack(stack_a, stack_b, 0);
		if (!ft_strcmp("rra", instructions->content))
			reverse_rotate_stack(stack_a, 0, 0);
		if (!ft_strcmp("rrb", instructions->content))
			reverse_rotate_stack(stack_b, 0, 0);
		if (!ft_strcmp("rrr", instructions->content))
			reverse_rotate_stack(stack_a, stack_b, 0);
		instructions = instructions->next;
	}
}

/*
** This function validates line.
** The instruction_is_valid() function checks to see if the string 'line'
** corresponds to a instructions (such as swap a - "sa").
**
** @param	char	*line	- string to validate.
**
** @return
** 		- The instruction_is_valid() function returns 1 if 'line' conatins a
** 		valid instructions; or 0 if it doesn't.
*/
int	instruction_is_valid(char *line)
{
	if (!ft_strcmp("sa", line) || !ft_strcmp("sb", line)
		|| !ft_strcmp("ss", line) || !ft_strcmp("pa", line)
		|| !ft_strcmp("pb", line) || !ft_strcmp("ra", line)
		|| !ft_strcmp("rb", line) || !ft_strcmp("rr", line)
		|| !ft_strcmp("rra", line) || !ft_strcmp("rrb", line)
		|| !ft_strcmp("rrr", line))
		return (1);
	return (0);
}
