/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:59:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/18 15:56:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE "Error\n"
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS "OK\n"
# endif

exit(EXIT_FAILURE);

void	swap_a();
void	swap_b();
void	swap_s();
void	push_a();
void	push_b();
void	rotate_a();
void	rotate_b();
void	rotate_r();
void	reverse_rotate_a();
void	reverse_rotate_b();
void	reverse_rotate_r();

#endif
