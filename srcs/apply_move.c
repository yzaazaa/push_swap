/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:09:56 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 10:22:13 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_rr(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*b)->top->data != to_push->data
		&& index_insert_a(*a, to_push->data))
		rr(a, b, 1);
	while (index_insert_a(*a, to_push->data))
		ra(a, 1);
	while ((*b)->top->data != to_push->data)
		rb(b, 1);
	pa(a, b, 1);
}

void	apply_rrr(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*b)->top->data != to_push->data
		&& index_insert_a(*a, to_push->data))
		rrr(a, b, 1);
	while (index_insert_a(*a, to_push->data))
		rra(a, 1);
	while ((*b)->top->data != to_push->data)
		rrb(b, 1);
	pa(a, b, 1);
}

void	apply_diff(t_stack **a, t_stack **b, t_node *to_push)
{
	int	index_topush_in_a;
	int	index_topush_in_b;

	index_topush_in_a = index_insert_a(*a, to_push->data);
	index_topush_in_b = get_index(*b, to_push->data);
	if (index_topush_in_b < (*b)->size - index_topush_in_b)
		while ((*b)->top->data != to_push->data)
			rb(b, 1);
	else
		while ((*b)->top->data != to_push->data)
			rrb(b, 1);
	if (index_topush_in_a < (*a)->size - index_topush_in_a)
		while (index_topush_in_a-- != 0)
			ra(a, 1);
	else
		while ((*a)->size - index_topush_in_a++ != 0)
			rra(a, 1);
	pa(a, b, 1);
}

void	push_to_a(t_stack **a, t_stack **b, t_node *to_push)
{
	if (to_push->instructions.move == 0)
		apply_diff(a, b, to_push);
	else if (to_push->instructions.move == 1)
		apply_rr(a, b, to_push);
	else if (to_push->instructions.move == 2)
		apply_rrr(a, b, to_push);
}
