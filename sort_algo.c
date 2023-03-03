/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:33:11 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/03 15:39:03 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_index(t_stack *stack)
{
	int	i;
	int	j;
	int	cnt;
	int	*result;

	result = malloc((stack->top + 1) * sizeof(int));
	protection(result);
	i = stack->top;
	while (i > -1)
	{
		cnt = 0;
		j = 0;
		while (j <= stack->top)
		{
			if (stack->elements[i] > stack->elements[j])
				cnt++;
			j++;
		}
		result[i] = cnt;
		i--;
	}
	return (result);
}

void	radix_sort(t_stack *stack_A, t_stack *stack_B, int *index)
{
	int	i;
	int	shift;
	int	amount_to_check;

	free(stack_A->elements);
	stack_A->elements = index;
	amount_to_check = count_bits(get_biggest_num(stack_A)) + 1;
	shift = 0;
	while (shift < amount_to_check)
	{
		i = stack_A->top;
		while (i > -1)
		{
			if (((stack_A->elements[stack_A->top] >> shift) & 1) == 0)
				push(stack_A, stack_B);
			else
				single_rev_rotate(stack_A);
			i--;
		}
		while (stack_B->top > -1)
			push(stack_B, stack_A);
		shift++;
	}
}

int	get_biggest_num(t_stack *stack)
{
	int	*index;
	int	i;

	index = get_index(stack);
	i = 0;
	while (i < (stack->top + 1))
	{
		if (index[i] == stack->top)
			return (free(index),stack->elements[i]);
		i++;
	}
	free(index);
	return (0);
}

int	count_bits(int x)
{
	int	count;

	count = -1;
	while (x)
	{
		count += 1;
		x >>= 1;
	}
	return (count);
}
