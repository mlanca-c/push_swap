/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:54:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/18 20:40:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

/*
*/
int	is_sorted(t_stack *stack_a);

/*
** This function checks for duplicates.
** The is_duplicate() function iterates a stack of integers - stack_a, looking
** for 'data', checking to see if the integer already exists.
**
** @param	t_stack	*stack_a	- stack to iterate and check if it contains data
** 								integer.
** @param	int		data		- integer used to check for duplicates.
**
** @return
** 		- The is_duplicate() function returns 1 if data isn't already in
** 		stack_a; and 0 if it is.
*/
int	is_duplicate(t_stack *stack_a, int data)
{
	t_stack	*temporary;
	if (!stack_a)
		return (0);
	temporary = stack_a;
	while (temporary)
	{
		if (temporary->data == data)
			return (1);
	}
	return (0);
}

/*
*/
void	fill_stack(char **argv, t_stack *stack_a)
{
	int	i;
	int	data;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		if (!ft_str_isdigit(argv[i]))
			exit_program(stack_a, NULL, 2);
		data = ft_atoi(argv[i]);
		if (is_duplicate(stack_a, data))
			exit_program(stack_a, NULL, 3);
		ft_stack_add_back(&stack_a, ft_stack_new(data));
		i++;
	}
	ft_putstr_fd("Print stack - done:\n", 1);
	ft_stack_print(&stack_a);
	ft_putstr_fd("done:\n", 1);
}
