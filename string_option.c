/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:51:03 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/10 14:49:15 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	string_option(char **argv)
{
	char	**strings;
	int		i;
	int		*index;
	t_stack	*stack_a;
	t_stack	*stack_b;

	strings = ft_split(argv[1], ' ');
	protection(strings);
	i = 0;
	while (strings[i])
		i++;
	check_input(i, strings);
	stack_a = init_stack('a', i);
	fill_stack_so(stack_a, i, strings);
	doubles_check(stack_a);
	index = get_index(stack_a);
	stack_b = init_stack('b', i);
	if (i < 4)
		small_sort(stack_a, index);
	else if (i < 7)
		medium_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, index);
	free(index);
	exit(0);
}

void	fill_stack_so(t_stack *stack, int j, char **strings)
{
	long	i;
	int		d;

	d = j - 1;
	while (d > -1)
	{
		i = ft_atol(strings[d]);
		if (i > INT_MAX || i < INT_MIN)
			error();
		init_push(stack, i);
		d--;
	}
}
