/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:39:24 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/05 17:47:52 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char c, int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->c = c;
	stack->elements = malloc(size * sizeof(int));
	if (!stack->elements)
		return (NULL);
	stack->top = -1;
	return (stack);
}

void	print_stack(t_stack *s)
{
	int	i;

	i = s->top;
	while (i > -1)
	{
		ft_printf("\n digit%d:%d", i, s->elements[i]);
		i--;
	}
}

void	double_swap(t_stack *stack1, t_stack *stack2)
{
	swap(stack1);
	swap(stack2);
	ft_printf("ss\n");
}

void	rev_rotate(t_stack *s)
{
	int	i;
	int	temp;

	temp = s->elements[s->top];
	i = s->top;
	while (i > 0)
	{
		s->elements[i] = s->elements[i - 1];
		i--;
	}
	s->elements[0] = temp;
}
