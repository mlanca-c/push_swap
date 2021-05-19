/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:59:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/19 20:45:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

/*
** Swap Instructions:
** For swapping the first two numbers of the respective stacks.
*/
void	swap_stack_a(t_stack *stack_a);
void	swap_stack_b(t_stack *stack_b);
void	swap_stacks(t_stack *stack_a, t_stack *stack_b);

/*
** Push Instructions:
** For pushing the first number of a stack to the other stack respectively.
*/
void	push_stack_a(t_stack **stack_a, t_stack **stack_b);
void	push_stack_b(t_stack **stack_b, t_stack **stack_a);

/*
** Rotate Instructions:
** To rotate a stack respectively.
*/
void	rotate_stack_a(t_stack **stack_a);
void	rotate_stack_b(t_stack **stack_b);
void	rotate_stacks(t_stack **stack_a, t_stack **stack_b);

/*
** Reverse Rotate Instructions:
** To reverse rotate a stack respectively.
*/
void	reverse_rotate_stack_a(t_stack **stack_a);
void	reverse_rotate_stack_b(t_stack **stack_b);
void	reverse_rotate_stacks(t_stack **stack_a, t_stack **stack_b);

#endif
