/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:47:12 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/18 00:32:41 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	get_index(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp->data != data)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	index_insert_b(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (data > stack->top->data && data < stack->bottom->data)
		i = 0;
	else if (data > get_max(stack) || data < get_min(stack))
		i = get_index(stack, get_max(stack));
	else
	{
		tmp = stack->top->next;
		while (stack->top->data < data  || tmp->data > data)
		{
			stack->top = stack->top->next;
			tmp = stack->top->next;
			i++;
		}
	}
	return (i);
}

int	index_insert_a(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (data < stack->top->data && data > stack->bottom->data)
		i = 0;
	else if (data > get_max(stack) || data < get_min(stack))
		i = get_index(stack, get_min(stack));
	else
	{
		tmp = stack->top->next;
		while (stack->top->data > data || tmp->data < data)
		{
			stack->top = stack->top->next;
			tmp = stack->top->next;
			i++;
		}
	}
	return (i);
}
