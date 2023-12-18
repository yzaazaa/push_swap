/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:36:16 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/18 00:03:30 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrarrb_count(t_stack *a, t_stack *b, int data, char c)
{
	int	i;

	if (c == 'a')
	{
		i = 0;
		if (index_insert_a(a, data))
			i = a->size - index_insert_a(a, data);
		if ((i < b->size - get_index(b, data)) && get_index(b, data))
			i = b->size - get_index(b, data);
	}
	if (c == 'b')
	{
		i = 0;
		if (index_insert_b(b, data))
			i = b->size - index_insert_b(b, data);
		if ((i < a->size - get_index(a, data)) && get_index(a, data))
			i = a->size - get_index(a, data);
	}
	return (i);
}

int	rarb_count(t_stack *a, t_stack *b, int data, char c)
{
	int	i;

	if (c == 'a')
	{
		i = index_insert_a(a, data);
		if (i < get_index(b, data))
			i = get_index(b, data);
	}
	if (c == 'b')
	{
		i = index_insert_b(b, data);
		if (i < get_index(a, data))
			i = get_index(a, data);
	}
	return (i);
}

int	rrarb_count(t_stack *a, t_stack *b, int data, char c)
{
	int	i;

	if (c == 'a')
	{
		i = 0;
		if (index_insert_a(a, data))
			i = a->size - index_insert_a(a, data);
		i = get_index(b, data) + i;
	}
	if (c == 'b')
	{
		i = 0;
		if (get_index(a, data))
			i = a->size - get_index(a, data);
		i = index_insert_b(b, data) + i;
	}
	return (i);
}

int	rarrb_count(t_stack *a, t_stack *b, int data, char c)
{
	int	i;


	if (c == 'a')
	{
		i = 0;
		if (get_index(b, data))
			i = b->size - get_index(b, data);
		i = index_insert_a(a, data) + i;
	}
	if (c == 'b')
	{
		i = 0;
		if (index_insert_b(b, data))
			i = b->size - index_insert_b(b, data);
		i = get_index(a, data) + i;
	}
	return (i);
}