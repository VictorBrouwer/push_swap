/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:44:21 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/01/09 10:59:50 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	char	c;
	int		*elements;
	int		top;
}			t_stack;
t_stack		*init_stack(char c, int size);
int			check_input(int argc, char **argv);
long		ft_atol(const char *str);
void		init_push(t_stack *s, int element);
void		push(t_stack *stack1, t_stack *stack2);
void		pop(t_stack *s);
void		swap(t_stack *s);
void		single_swap(t_stack *s);
void		double_swap(t_stack *stack1, t_stack *stack2);
void		rotate(t_stack *s);
void		single_rotate(t_stack *s);
void		double_rotate(t_stack *stack1, t_stack *stack2);
void		rev_rotate(t_stack *s);
void		single_rev_rotate(t_stack *s);
void		double_rev_rotate(t_stack *stack1, t_stack *stack2);
void		print_stack(t_stack *s);
int			get_pos_low(t_stack *stack_A);
void		small_sort(t_stack *stack, int	*index);
void		medium_sort(t_stack *stack_A, t_stack *stack_B);
void		doubles_check(t_stack *stack);
int			*get_index(t_stack *stack);
void		radix_sort(t_stack *stack_A, t_stack *stack_B);
int			get_biggest_num(t_stack *stack);
int			count_bits(int x);
int			check_if_sorted(t_stack *stack);
void		error(void);

#endif