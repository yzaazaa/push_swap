/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:47:12 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/21 11:51:59 by yzaazaa          ###   ########.fr       */
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

int	index_insert_a(t_stack *stack, int data)
{
	int		i;
	t_node	*tmp;

	if (data < stack->bottom->data && data > stack->top->data)
		return (0);
	if (data < get_min(stack))
		return (get_index(stack, get_min(stack)) + 1);
	if (data > get_max(stack))
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