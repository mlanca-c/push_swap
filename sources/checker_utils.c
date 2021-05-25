/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:55:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/25 18:14:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
void	exit_checker(t_stack *stack_a, t_stack *stack_b, t_list *instructions,
			int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (instructions)
		ft_lstclear(&instructions);
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
