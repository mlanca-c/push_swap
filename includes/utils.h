/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:12:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/26 15:59:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

/*
** push_swap_utils.c Functions
*/
void	move_to_stack(char **argv, t_stack **stack_a);
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status);

/*
** instructions.c Functions
*/
void	swap_stack(t_stack *mandatory, t_stack *optional, char *message);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message);
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *message);
void	reverse_rotate_stack(t_stack **mandatory,
			t_stack **optional,
			char *message);

#endif
