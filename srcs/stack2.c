/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:32:29 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 10:03:57 by yzaazaa          ###   ########.fr       */
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
