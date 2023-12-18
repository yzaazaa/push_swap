/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:32:29 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/17 06:51:00 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	in_stack(t_stack *stack, int data)
{
	t_node	*tmp;

	if (!stack)
		return (0);
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_stack(t_stack *a, t_stack *b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	if (a && !b)
	{
		tmp_a = a->top;
		while (tmp_a)
		{
			ft_putnbr_fd(tmp_a->data, 1);
			ft_putchar_fd('\n', 1);
			tmp_a = tmp_a->next;
		}
		ft_putstr_fd("_\na", 1);
		return ;
	}
	if (!a && b)
	{
		tmp_a = a->top;
		while (tmp_a)
		{
			ft_putnbr_fd(tmp_a->data, 1);
			ft_putchar_fd('\n', 1);
			tmp_a = tmp_a->next;
		}
		ft_putstr_fd("_\na", 1);
		return ;
	}
	tmp_a = a->top;
	tmp_b = b->top;
	if (a->size || b->size)
	{
		while (tmp_a || tmp_b)
		{
			if (tmp_a)
				ft_putnbr_fd(tmp_a->data, 1);
			else
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(' ', 1);
			if (tmp_b)
				ft_putnbr_fd(tmp_b->data, 1);
			else
				ft_putchar_fd(' ', 1);
			ft_putchar_fd('\n', 1);
			if (tmp_a)
				tmp_a = tmp_a->next;
			if (tmp_b)
				tmp_b = tmp_b->next;
		}
	}
	ft_putendl_fd("_ _\na b", 1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	if (print == 1)
		ft_putendl_fd("rrr", 1);
	rra(a, 0);
	rrb(b, 0);
}

int	get_min(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	tmp = stack->top;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	tmp = stack->top;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
