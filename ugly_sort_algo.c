/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ugly_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:12:13 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/09 14:43:32 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *stack)
{
	int	*index;
	int	i;
	int	cnt;

	index = get_index(stack);
	i = stack->top;
	cnt = 0;
	while (i > -1)
	{
		if (cnt != index[i])
			return (-1);
		i--;
		cnt++;
	}
	return (0);
}

void	small_sort(t_stack *stack, int	*index)
{
	if (check_if_sorted(stack) == 0)
		return ;
	if (stack->top == 1)
		return (single_swap(stack));
	else if (index[stack->top] == 0)
	{
		single_rotate(stack);
		return (single_swap(stack));
	}
	else if (index[1] == 0)
	{
		if (index[stack->top] == 1)
			return (single_swap(stack));
		else
			return (single_rev_rotate(stack));
	}
	if (index[stack->top] == 1)
		return (single_rotate(stack));
	single_swap(stack);
	return (single_rotate(stack));
}

void	medium_sort(t_stack *stack_A, t_stack *stack_B)
{
	int	*index;

	if (check_if_sorted(stack_A) == 0)
		return ;
	while (stack_A->top > 2)
	{
		while ((stack_A->top - get_pos_low(stack_A)) > 0)
			single_rev_rotate(stack_A);
		push(stack_A, stack_B);
	}
	index = get_index(stack_A);
	small_sort(stack_A, index);
	while (stack_B->top > -1)
	{
		push(stack_B, stack_A);
	}
}

int	get_pos_low(t_stack *stack)
{
	int	*index;
	int	i;

	index = get_index(stack);
	i = stack->top;
	while (i > -1)
	{
		if (index[i] == 0)
			return (i);
		i--;
	}
	return (-1);
}
