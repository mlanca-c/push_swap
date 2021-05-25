/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:50:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/25 17:19:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "utils.h"
#include <stdio.h>

/*
** push_swap.c Functions
*/
void	get_sorting(t_stack **stack_a, t_stack **stack_b);
void	sorting_small_algorithm(t_stack **stack_a);
void	sorting_medium_algorithm(t_stack **stack_a, t_stack **stack_b);
void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b);


/*
** sorting_utils.c Functions
*/
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);

#endif
