/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/05/29 18:05:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//
// gcc -Wall -Wextra -Werror my_small_tester.c -Ilibft -Ilibft/stack libft/*.c libft/stack/*.c && ./a.out `ruby -e "puts (1..25).to_a.shuffle.join(' ')"`

void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message)
{
	if (!(*from_stack))
		return ;
	ft_stack_add_front(to_stack, ft_stack_new((*from_stack)->data));
	ft_stack_remove(from_stack);
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

void	get_chunks(t_stack **stack_a, t_stack **chunks)
{
	int		median;

	median = ft_stack_median(*stack_a);
	ft_stack_add_back(chunks, ft_stack_new(median));
	ft_stack_sort(chunks);
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
			printf(", ");
		else
			printf("\n");
		temporary = temporary->next;
	}
}

int	is_duplicate(int n, t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->data == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
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
			printf("Error\n");
		data = ft_atoi(argv[i]);
		if (!ft_isint(data))
			printf("Error\n");
		new_node = ft_stack_new(data);
		if (!new_node)
			printf("Error\n");
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	if (ft_stack_is_duplicate(*stack_a))
		printf("Error\n");
}

int	get_hold_first(t_stack *stack_a, t_stack **chunks)
{
	int	first;
	int	max;
	int	min;

	min = (*chunks)->data;
	max = (*chunks)->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

int	get_hold_second(t_stack *stack_a, t_stack **chunks)
{
	int	second;
	int	max;
	int	min;

	stack_a = ft_stack_last(stack_a);
	min = (*chunks)->data;
	max = (*chunks)->next->data;
	second = 1;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (second);
		second++;
		stack_a = stack_a->previous;
	}
	return (second);
}

void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack **chunks)
{
	int	first;
	int	second;

	first = get_hold_first(*stack_a, chunks);
	second = get_hold_second(*stack_a, chunks);
	if (first <= second)
	{
		while (first--)
			rotate_stack(stack_a, 0, "ra\n");
	}
	else
	{
		while (second--)
			reverse_rotate_stack(stack_a, 0, "rra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
}

void	split_b_back_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *chunks)
{
	int	first;
	int	second;

	first = get_hold_first(*stack_b, &chunks);
	second = get_hold_second(*stack_b, &chunks);
	if (first <= second)
	{
		while (first--)
		{
			if ((*stack_b)->data == ft_stack_min_value(*stack_b))
			{
				push_stack(stack_b, stack_a, "pa\n");
				if (first)
					rotate_stack(stack_a, stack_b, "rr\n");
				else
					rotate_stack(stack_a, 0, "ra\n");
			}
			else
				rotate_stack(stack_b, 0, "rb\n");
		}
	}
	else
	{
		while (second--)
		{
			if ((*stack_b)->data == ft_stack_min_value(*stack_b))
			{
				push_stack(stack_b, stack_a, "pa\n");
				rotate_stack(stack_a, 0, "ra\n");
			}
			else
				reverse_rotate_stack(stack_b, 0, "rrb\n");
		}
	}
	push_stack(stack_b, stack_a, "pa\n");
}

void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack **chunks)
{
	ft_stack_remove(chunks);
	get_chunks(stack_b, chunks);
	printf("chunks: ");
	stack_print(*chunks);
	while (ft_stack_has_above(*stack_b, (*chunks)->data))
		split_b_back_to_a(stack_b, stack_a, *chunks);
	printf("stack_a: ");
	stack_print(*stack_a);
	printf("stack_b: ");
	stack_print(*stack_b);
}

int	ra_closest(t_stack *stack_b, int value)
{
	int	first;
	int	half;

	first = 0;
	half = ft_stack_size(stack_b) / 2;
	while (stack_b)
	{
		if (stack_b->data == value)
			break ;
		first++;
		stack_b = stack_b->next;
	}
	if (first <= half)
		return (1);
	return (0);
}


void	merge_sort_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*duplicated;

	duplicated = ft_stack_duplicate(stack_b);
	ft_stack_sort(&duplicated);
	while (ft_stack_size(stack_b))
	{
		printf("duplicated: ");
		stack_print(duplicated);
		printf("stack a: ");
		stack_print(stack_a);
		printf("stack b: ");
		stack_print(stack_b);
		if (ra_closest(stack_b, duplicated->data))
		{
			while(stack_b->data != duplicated->data)
			{
				if (stack_b->data == ft_stack_last(stack_b)->data)
					push_stack(&stack_b, &stack_a, "pa\n");
				rotate_stack(&stack_b, 0, "rb\n");
			}
			push_stack(&stack_b, &stack_a, "pa\n");
			rotate_stack(&stack_a, 0, "ra\n");
		}
		else
		{
			while(stack_b->data != duplicated->data)
			{
				if (stack_b->data == ft_stack_last(stack_b)->data)
					push_stack(&stack_b, &stack_a, "pa\n");
				reverse_rotate_stack(&stack_b, 0, "rb\n");
			}
			push_stack(&stack_b, &stack_a, "pa\n");
			rotate_stack(&stack_a, 0, "ra\n");
		}
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*chunks;

	if (argc == 1)
		exit(1);
	printf("This is a tester for the small functions that I implemented in push_swap project.\n");

	// Creating a stack.
	stack_a = 0;
	stack_b = 0;
	move_to_stack(&argv[1], &stack_a);
	printf("init stack_a: ");
	stack_print(stack_a);

	// Creating chunk with limits.
	chunks = ft_stack_new(ft_stack_min_value(stack_a));
	ft_stack_add_back(&chunks, ft_stack_new(ft_stack_max_value(stack_a)));
	int median = ft_stack_median(stack_a);
	ft_stack_add_back(&chunks, ft_stack_new(median));
	ft_stack_sort(&chunks);
	printf("chunks: ");
	stack_print(chunks);

	// Testing split_a_to_b
	while (ft_stack_size(stack_b) < chunks->next->data)
		split_a_to_b(&stack_a, &stack_b, &chunks);
	printf("stack_a: ");
	stack_print(stack_a);
	printf("stack_b: ");
	stack_print(stack_b);

	// Testing merge_half_to_a
	printf("Testing merge half to a \n");
	if (chunks->next->data - chunks->data > 20)
		merge_half_to_a(&stack_a, &stack_b, &chunks);

	// Testing merge_sort_to_a
	printf("Testing merge sort to a \n");
	if (chunks->next->data - chunks->data <= 20)
		merge_sort_to_a(stack_a, stack_b);
}
