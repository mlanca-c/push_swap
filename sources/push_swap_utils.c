/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:54:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 17:34:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*/
int	is_sorted(t_stack *stack_a);

/*
*/
void	fill_stack(char **argv, t_stack **stack_a)
{
	int			i;
	long long	data;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			exit_program(*stack_a, NULL, 0);
		data = ft_atoi(argv[i]);
		if ((ft_stack_is_duplicate(*stack_a, data) && i != 0)
			|| !ft_isint(data))
			exit_program(*stack_a, NULL, 0);
		ft_stack_add_back(stack_a, ft_stack_new(data));
		i++;
	}
}
