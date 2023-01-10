/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:41:36 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/10 15:50:43 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*index;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2)
		string_option(argv);
	check_input(argc, argv);
	stack_a = init_stack('a', (argc - 1));
	fill_stack(stack_a, argc, argv);
	doubles_check(stack_a);
	index = get_index(stack_a);
	stack_b = init_stack('b', (argc - 1));
	if (argc < 5)
		small_sort(stack_a, index);
	else if (argc < 8)
		medium_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, index);
	free(index);
	return (0);
}

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	long	i;
	int		d;

	d = argc - 1;
	while (d > 0)
	{
		i = ft_atol(argv[d]);
		if (i > INT_MAX || i < INT_MIN)
			error();
		init_push(stack, i);
		d--;
	}
}

void	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		error();
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' && argv[i][1])
			j++;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				error();
			j++;
		}
		i++;
	}
}

void	doubles_check(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	while (i <= stack->top)
	{
		j = 0;
		while (j < i)
		{
			if (stack->elements[i] == stack->elements[j])
			{
				free(stack->elements);
				free(stack);
				error();
			}
			j++;
		}
		i++;
	}
}

long	ft_atol(const char *str)
{
	int		x;
	int		sign;
	long	result;

	x = 0;
	sign = 1;
	result = 0;
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10;
		result = result + (str[x] - '0');
		x++;
	}
	return (result * sign);
}
