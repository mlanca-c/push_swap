/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:17:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/26 15:58:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** This function swaps the first 2 elements at the top of a stack - either
** 'stack_a' or 'stack_b' or both - with one another.
**
** @param	t_stack	**mandatory	- Swap the first two elements of this stack with
** 								one another. This stack will always be swapped.
** @param	t_stack	**optional	- Swap the first two elements of this stack with
** 								one another. This stack is optional and doesn't
** 								need to be swapped.
** @param	char	*message	- message to be displayed at the end of the
** 								function. 
** 								Possible messages:
** 									"sa\n"	- swap the first 2 elements of
** 											'stack_a'.
** 									"sb\n:	- swap the first 2 elements of
** 											'stack_b'.
** 									"ss\n"	- swap the first 2 elements of
** 											both stacks.
*/
void	swap_stack(t_stack *mandatory, t_stack *optional, char *message)
{
	ft_swap(&(mandatory->data), &(mandatory->next->data));
	if (optional)
		ft_swap(&(optional->data), &(optional->next->data));
	ft_putstr_fd(message, 1);
}

/*
** This function takes the first element at the top of 'from_stack' and puts it
** at the top of 'to_stack'.
**
** @param	t_stack	**from_stack	- stack to take the integer from.
** @param	t_stack	**to_stack		- stack where the integer is supposed to go.
** @param	char	*message	- message to be displayed at the end of the
** 								function.
** 								Possible messages:
** 									"pa\n"	- push first element of 'stack_b' to
** 											the top of 'stack_a'.
** 									"pb\n"	- push first element of 'stack_a' to
** 											the top of 'stack_b'.
*/
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message)
{
	if (!(*from_stack))
		return ;
	ft_stack_add_front(to_stack, ft_stack_new((*from_stack)->data));
	ft_stack_remove(from_stack);
	ft_putstr_fd(message, 1);
}

/*
** This function shifts up all elements of a stack by 1 - the first element
** becomes the last one.
**
** @param	t_stack	**mandatory	- Stack to rotate - its first element becomes
** 								its last one. This stack will always be rotated.
** @param	t_stack	**mandatory	- Stack to rotate - its first element becomes
** 								its last one. This stack is optional and doesn't
** 								need to be rotated.
** @param	char	*message	- message to be displayed at the end of the
** 								function. 
** 								Possible messages:
** 									"ra\n"	- Rotate all the elements of
** 									   		'stack_a'.
** 									"rb\n"	- Rotate all the elements of
** 									 	  	'stack_b'.
** 									"rr\n"	- Rotate all the elements of
** 											both stacks.
*/
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *message)
{
	int	data;

	data = ft_stack_first(*mandatory)->data;
	ft_stack_remove(mandatory);
	ft_stack_add_back(mandatory, ft_stack_new(data));
	if (optional)
	{
		data = ft_stack_first(*optional)->data;
		ft_stack_remove(optional);
		ft_stack_add_back(optional, ft_stack_new(data));
	}
	ft_putstr_fd(message, 1);
}

/*
** This function shifts down all elements of a stack by 1 - the last element
** becomes the first one.
**
** @param	t_stack	**mandatory	- Stack to reverse rotate - its first element
** 								becomes its last one. This stack will always be
** 								rotated.
** @param	t_stack	**mandatory	- Stack to reverse rotate - its first element
** 								becomes its last one. This stack is optional and
** 								doesn't need to be rotated.
** @param	char	*message	- message to be displayed at the end of the
** 								function. 
** 								Possible messages:
** 									"rra\n"	- Reverse rotate all the elements of
** 											'stack_a'.
** 									"rrb\n"	- Reverse rotate all the elements of
** 											'stack_b'.
** 									"rrr\n"	- Reverse rotate all the elements of
** 											both stacks.
*/
void	reverse_rotate_stack(t_stack **mandatory,
			t_stack **optional,
			char *message)
{
	int		data;
	t_stack	*last_node;

	last_node = ft_stack_last(*mandatory);
	data = last_node->data;
	ft_stack_remove(&last_node);
	ft_stack_add_front(mandatory, ft_stack_new(data));
	if (optional)
	{
		last_node = ft_stack_last(*optional);
		data = last_node->data;
		ft_stack_remove(&last_node);
		ft_stack_add_front(optional, ft_stack_new(data));
	}
	ft_putstr_fd(message, 1);
}
