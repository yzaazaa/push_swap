/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:47:12 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/24 10:30:50 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	get_index(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp && tmp->data != data)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return (-1);
	return (i);
}

int	index_insert_a(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	if (data < stack->top->data && data > stack->bottom->data)
		return (0);
	if (data < get_min(stack) || data > get_max(stack))
		return (get_index(stack, get_min(stack)));
	i = 0;
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->data < data && tmp->next->data > data)
			return (i + 1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	index_insert_b(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	if (data > stack->top->data && data < stack->bottom->data)
		return (0);
	if (data < get_min(stack) || data > get_max(stack))
		return (get_index(stack, get_max(stack)));
	i = 0;
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->data > data && tmp->next->data < data)
			return (i + 1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
