/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:20:09 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/26 13:20:58 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

/*
*/
void	print_stacks(t_stack **stack_a, t_stack **stack_b, int *size_a,
		int *size_b)
{
	if (*size_a > *size_b && (*size_a)--)
	{
		printf("%-3d\n", (*stack_a)->data);
		(*stack_a) = (*stack_a)->next;
	}
	else if (*size_b > *size_a && (*size_b)--)
	{
		printf("        %-3d\n", (*stack_b)->data);
		(*stack_b) = (*stack_b)->next;
	}
	else if ((*size_a)-- && (*size_b)--)
	{
		printf("%-3d     %-3d\n", (*stack_a)->data, (*stack_b)->data);
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = (*stack_b)->next;
	}
}

/*
*/
void	print_both_stacks(t_stack *stack_a, t_stack *stack_b, char *message)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	printf("------------\n%s:\n\n\n", message);
	while (size_a >= 0 && size_b >= 0)
		print_stacks(&stack_a, &stack_b, &size_a, &size_b);
	printf("___     ___\n a       b\n\n");
}
