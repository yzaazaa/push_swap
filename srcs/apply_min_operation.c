/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_min_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:08:48 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/18 00:13:46 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rarb_apply(t_stack **a, t_stack **b, int data, char c)
{
	if (c == 'a')
	{
		while ((*a)->top->data != data && index_insert_b(*b, data) > 0)
			rr(a, b, 1);
		while ((*a)->top->data != data)
			ra(a, 1);
		while (index_insert_b(*b, data) > 0)
			rb(b, 1);
		pb(a, b, 1);
	}
	if (c == 'b')
	{
		while ((*b)->top->data != data && index_insert_a(*a, data) > 0)
			rr(a, b, 1);
		while ((*b)->top->data != data)
			rb(a, 1);
		while (index_insert_b(*b, data) > 0)
			ra(b, 1);
		pa(a, b, 1);
	}
	return (-1);
}

int	rrarrb_apply(t_stack **a, t_stack **b, int data, char c)
{
	if (c == 'a')
	{
		while ((*a)->top->data != data && index_insert_b(*b, data) > 0)
			rrr(a, b, 1);
		while ((*a)->top->data != data)
			rra(a, 1);
		while (index_insert_b(*b, data) > 0)
			rrb(b, 1);
		pb(a, b, 1);
	}
	if (c == 'b')
	{
		while ((*b)->top->data != data && index_insert_a(*a, data) > 0)
			rrr(a, b, 1);
		while ((*b)->top->data != data)
			rrb(a, 1);
		while (index_insert_b(*b, data) > 0)
			rra(b, 1);
		pa(a, b, 1);
	}
	return (-1);
}

int	rarrb_apply(t_stack **a, t_stack **b, int data, char c)
{
	if (c == 'a')
	{
		while ((*a)->top->data != data)
			ra(a, 1);
		while (index_insert_b(*b, data) > 0)
			rrb(b, 1);
		pb(a, b, 1);
	}
	if (c == 'b')
	{
		while (index_insert_a(*b, data) > 0)
			ra(b, 1);
		while ((*b)->top->data != data)
			rrb(a, 1);
		pa(a, b, 1);
	}
	return (-1);
}

int	rrarb_apply(t_stack **a, t_stack **b, int data, char c)
{
	if (c == 'a')
	{
		while ((*a)->top->data != data)
			rra(a, 1);
		while (index_insert_b(*b, data) > 0)
			rb(b, 1);
		pb(a, b, 1);
	}
	if (c == 'b')
	{
		while (index_insert_a(*b, data) > 0)
			rra(b, 1);
		while ((*b)->top->data != data)
			rb(a, 1);
		pa(a, b, 1);
	}
	return (-1);
}
