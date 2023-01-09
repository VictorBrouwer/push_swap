/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:16:04 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/09 13:43:53 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push(t_stack *s, int element)
{
	if (s->top == 2147483646)
	{
		return ;
	}
	s->top++;
	s->elements[s->top] = element;
}

void	push(t_stack *stack1, t_stack *stack2)
{
	init_push(stack2, stack1->elements[stack1->top]);
	pop(stack1);
	ft_printf("p%c\n", stack2->c);
}

void	pop(t_stack *s)
{
	if (s->top < 0)
		return ;
	s->top--;
}

void	swap(t_stack *s)
{
	int	temp;

	if (s->top < 1)
		return ;
	temp = s->elements[s->top];
	s->elements[s->top] = s->elements[s->top - 1];
	s->elements[s->top - 1] = temp;
}

void	single_swap(t_stack *s)
{
	swap(s);
	ft_printf("s%c\n", s->c);
}
