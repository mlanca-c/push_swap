/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/02 19:01:00 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	stack_print_reverse(t_stack *stack);
void	stack_print(t_stack *stack);
void	move_to_stack(char **argv, t_stack **stack_a);
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status);
void	swap_stack(t_stack *mandatory, t_stack *optional, char *message);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message);
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *message);
void	reverse_rotate_stack(t_stack **mandatory, t_stack **optional, char *message);

// gcc -Wall -Wextra -Werror my_small_tester.c -Ilibft -Ilibft/stack libft/*.c
// libft/stack/*.c sources/instructions.c  && ./a.out `ruby -e "puts (1..25).to_a.shuffle.join(' ')"`

// TESTED PART
void	get_new_limit(t_stack **limits, t_stack *stack_a)
{
	t_stack	*duplicate;
	int		min_idx;
	int		max_idx;
	int		new;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	min_idx = ft_stack_find(duplicate, (*limits)->data);
	max_idx = ft_stack_find(duplicate, (*limits)->next->data);
	if ((max_idx - min_idx) % 2)
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx));
	else
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx - 1));
	ft_stack_add_front(limits, ft_stack_new(new));
	ft_stack_sort(limits);
}

int	count_in_between(t_stack *stack_a, t_stack *limits)
{
	t_stack	*duplicate;
	int		max_idx;
	int		min_idx;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	min_idx = ft_stack_find(duplicate, limits->data);
	max_idx = ft_stack_find(duplicate, limits->next->data);
	return (max_idx - min_idx + 1);
}

int	get_hold_first(t_stack *stack_a, t_stack *limits)
{
	int	first;
	int	max;
	int	min;

	min = limits->data;
	max = limits->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data > min && stack_a->data < max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

int	get_hold_second(t_stack *stack_a, t_stack *limits)
{
	int	second;
	int	max;
	int	min;

	stack_a = ft_stack_last(stack_a);
	min = limits->data;
	max = limits->next->data;
	second = 1;
	while (stack_a)
	{
		if (stack_a->data > min && stack_a->data < max)
			return (second);
		second++;
		stack_a = stack_a->previous;
	}
	return (second);
}

void	get_holds(int *first, int *second, t_stack *stack_a, t_stack *limits)
{
	int		min;
	int		max;
	t_stack	*stack_b;

	min = limits->data;
	max = limits->next->data;
	*first = 0;
	while (stack_a->next)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			break ;
		(*first)++;
		stack_a = stack_a->next;
	}
	stack_b = ft_stack_last(stack_a);
	*second = 1;
	while (stack_b->previous)
	{
		if (stack_b->data >= min && stack_b->data <= max)
			break ;
		(*second)++;
		stack_b = stack_b->previous;
	}
}

void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	int	first;
	int	second;
	int size;

	size = count_in_between(*stack_a, limits);
	while (ft_stack_size(*stack_b) < size)
	{
		get_holds(&first, &second, *stack_a, limits);
		if (first <= second)
			while (first--)
				rotate_stack(stack_a, 0, "ra\n");
		else
			while (second--)
				reverse_rotate_stack(stack_a, 0, "rra\n");
		push_stack(stack_a, stack_b, "pb\n");
	}
}

// NOT TESTED PART
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	int	first;
	int	second;
	int	size;

	get_new_limit(&limits, *stack_b);
	size = count_in_between(*stack_b, limits->next) - 1;
	while (ft_stack_size(*stack_b) > size)
	{
		first = get_hold_first(*stack_b, limits->next);
		second = get_hold_second(*stack_b, limits->next);
		if (first <= second)
			while (first--)
				rotate_stack(stack_b, 0, "rb\n");
		else
			while (second--)
				reverse_rotate_stack(stack_b, 0, "rrb\n");
		push_stack(stack_b, stack_a, "pa\n");
	}
}

void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	first = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&first);
	second = ft_stack_last(first);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == first->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			rotate_stack(stack_a, 0, "ra\n");
			first = first->next;
		}
		else if ((*stack_b)->data == second->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			second = second->previous;
		}
		else
			rotate_stack(stack_b, 0, "rb\n");
	}

}

void	rotate_until_sorted(t_stack **stack_a, t_stack *limits)
{
	while (ft_stack_last(*stack_a)->data != limits->next->data)
		reverse_rotate_stack(stack_a, 0, "rra\n");
}

void	sorting_big_algorithm(t_stack **stack_a, t_stack **stack_b,
		t_stack **limits)
{
	if (ft_stack_size(*limits) == 1)
		return ;
	get_new_limit(limits, *stack_a);
	if (!ft_stack_size(*stack_b))
		split_a_to_b(stack_a, stack_b, *limits);
	if (count_in_between(*stack_b, *limits) >= 20)
		merge_half_to_a(stack_a, stack_b, *limits);
	merge_sort_to_a(stack_a, stack_b);
	rotate_until_sorted(stack_a, *limits);
	ft_stack_remove(limits);
	//sorting_big_algorithm(stack_a, stack_b, limits);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*limits;

	if (argc == 1)
		exit(1);
	printf("This is a tester for the small functions that I implemented in push_swap project.\n");

	// Creating a stack.
	stack_a = 0;
	stack_b = 0;
	move_to_stack(&argv[1], &stack_a);
	printf("\ninit stack_a: ");
	stack_print(stack_a);

	//Creating Limits
	int maximum = ft_stack_max_value(stack_a);
	int minimum = ft_stack_min_value(stack_a);
	limits = ft_stack_new(minimum);
	ft_stack_add_back(&limits, ft_stack_new(maximum));
	printf("\ninit limits: ");
	stack_print(limits);

	// Calling sorting_big_algorithm() function
	if (ft_stack_size(stack_a) > 5)
		sorting_big_algorithm(&stack_a, &stack_b, &limits);
	printf("\nfinal stack_a: ");
	stack_print(stack_a);
}

void	swap_stack(t_stack *mandatory, t_stack *optional, char *message)
{
	ft_swap(&(mandatory->data), &(mandatory->next->data));
	if (optional)
		ft_swap(&(optional->data), &(optional->next->data));
	ft_putstr_fd(message, 1);
}

void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message)
{
	if (!(*from_stack))
		return ;
	ft_stack_add_front(to_stack, ft_stack_new((*from_stack)->data));
	ft_stack_remove(from_stack);
	ft_putstr_fd(message, 1);
}

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

void	stack_print_reverse(t_stack *stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = ft_stack_last(stack);
	while (temporary)
	{
		printf("%d", temporary->data);
		if (temporary->previous)
			printf(" ");
		else
			printf("\n");
		temporary = temporary->previous;
	}
}
void	stack_print(t_stack *stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = stack;
	while (temporary)
	{
		printf("%d", temporary->data);
		if (temporary->next)
			printf(" ");
		else
			printf("\n");
		temporary = temporary->next;
	}
}

void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!status)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	move_to_stack(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			exit_push_swap(*stack_a, 0, 0);
		data = ft_atoi(argv[i]);
		if (!ft_isint(data))
			exit_push_swap(*stack_a, 0, 0);
		new_node = ft_stack_new(data);
		if (!new_node)
			exit_push_swap(*stack_a, 0, 0);
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	if (ft_stack_is_duplicate(*stack_a))
		exit_push_swap(*stack_a, 0, 0);
}
