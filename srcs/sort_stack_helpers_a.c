/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_helpers_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:26:44 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/24 10:11:57 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_instructions	fill_instructions_a(t_stack *a, t_stack *b, int data)
{
	int				index_b;
	int				index_a;
	int				move[3];
	t_instructions	instructions;

	index_b = index_insert_b(b, data);
	index_a = get_index(a, data);
	move[0] = min(index_b, b->size - index_b) + min(index_a, a->size - index_a);
	move[1] = max(index_b, index_a) + 1;
	move[2] = max(a->size - index_a, b->size - index_b) + 1;
	instructions.min_instructions = min(move[0] + 1, min(move[1], move[2]));
	if (instructions.min_instructions == (move[0] + 1))
		instructions.move = 0;
	else if (instructions.min_instructions == move[1])
		instructions.move = 1;
	else if (instructions.min_instructions == move[2])
		instructions.move = 2;
	return (instructions);
}

static void	apply_diff_a(t_stack **a, t_stack **b, t_node *to_push)
{
	int	index_topush_in_a;
	int	index_topush_in_b;

	index_topush_in_a = get_index(*a, to_push->data);
	index_topush_in_b = index_insert_b(*b, to_push->data);
	if (index_topush_in_a < (*a)->size - index_topush_in_a)
		while ((*a)->top->data != to_push->data)
			ra(a, 1);
	else
		while ((*a)->top->data != to_push->data)
			rra(a, 1);
	if (index_topush_in_b < (*b)->size - index_topush_in_b)
		while (index_topush_in_b-- != 0)
			rb(b, 1);
	else
		while ((*b)->size - index_topush_in_b++ != 0)
			rrb(b, 1);
	pb(a, b, 1);
}

static void	apply_rr_a(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*a)->top->data != to_push->data
		&& index_insert_b(*b, to_push->data))
		rr(a, b, 1);
	while (index_insert_b(*b, to_push->data))
		rb(b, 1);
	while ((*a)->top->data != to_push->data)
		ra(a, 1);
	pb(a, b, 1);
}

static void	apply_rrr_a(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*a)->top->data != to_push->data
		&& index_insert_b(*b, to_push->data))
		rrr(a, b, 1);
	while (index_insert_b(*b, to_push->data))
		rrb(b, 1);
	while ((*a)->top->data != to_push->data)
		rra(a, 1);
	pb(a, b, 1);
}

void	push_min_instructions_to_b(t_stack **a, t_stack **b, t_node *to_push)
{
	if (to_push->instructions.move == 0)
		apply_diff_a(a, b, to_push);
	else if (to_push->instructions.move == 1)
		apply_rr_a(a, b, to_push);
	else if (to_push->instructions.move == 2)
		apply_rrr_a(a, b, to_push);
}
