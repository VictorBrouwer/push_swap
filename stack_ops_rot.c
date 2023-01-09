/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:50 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/09 15:02:03 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_rotate(t_stack *s)
{
	rotate(s);
	ft_printf("rr%c\n", s->c);
}

void	double_rotate(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1);
	rotate(stack2);
	ft_printf("rr\n");
}

void	rotate(t_stack *s)
{
	int	i;
	int	temp;

	temp = s->elements[0];
	i = 0;
	while (i < s->top)
	{
		s->elements[i] = s->elements[i + 1];
		i++;
	}
	s->elements[s->top] = temp;
}

void	single_rev_rotate(t_stack *s)
{
	rev_rotate(s);
	ft_printf("r%c\n", s->c);
}

void	double_rev_rotate(t_stack *stack1, t_stack *stack2)
{
	rev_rotate(stack1);
	rev_rotate(stack2);
	ft_printf("rrr\n");
}
