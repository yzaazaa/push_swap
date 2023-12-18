/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:31:08 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/17 23:53:01 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_operations_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_node	*tmp;

	tmp = a->top;
	i = rrarrb_count(a, b, tmp->data, 'b');
	while (tmp)
	{
		if (i > rarb_count(a, b, tmp->data, 'b'))
			i = rarb_count(a, b, tmp->data, 'b');
		if (i > rrarrb_count(a, b, tmp->data, 'b'))
			i = rrarrb_count(a, b, tmp->data, 'b');
		if (i > rarrb_count(a, b, tmp->data, 'b'))
			i = rarrb_count(a, b, tmp->data, 'b');
		if (i > rrarb_count(a, b, tmp->data, 'b'))
			i = rrarb_count(a, b, tmp->data, 'b');
		tmp = tmp->next;
	}
	return (i);
}

int	min_operations_ba(t_stack *a, t_stack *b)
{
	int	i;
	t_node *tmp;

	tmp = b->top;
	i = rrarrb_count(a, b, tmp->data, 'a');
	while (tmp)
	{
		if (i > rarb_count(a, b, tmp->data, 'a'))
			i = rarb_count(a, b, tmp->data, 'a');
		if (i > rrarrb_count(a, b, tmp->data, 'a'))
			i = rrarrb_count(a, b, tmp->data, 'a');
		if (i > rarrb_count(a, b, tmp->data, 'a'))
			i = rarrb_count(a, b, tmp->data, 'a');
		if (i > rrarb_count(a, b, tmp->data, 'a'))
			i = rrarb_count(a, b, tmp->data, 'a');
		tmp = tmp->next;
	}
	return (i);
}