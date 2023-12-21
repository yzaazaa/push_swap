/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:37:45 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/21 12:03:10 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_instructions	fill_instructions(t_stack *a, t_stack *b, int data)
{
	int	index_b;
	int	index_a;
	int	diff;
	int	rr;
	int	rrr;
	t_instructions	instructions;

	index_a = index_insert_a(a, data);
	index_b = get_index(b, data);
	diff = min(index_b, b->size - index_b) + min(index_a, a->size - index_a) + 1;
	rr = max(index_b, index_a) + 1;
	rrr = max(a->size - index_a, b->size - index_b) + 1;
	instructions.min_instructions = min(diff, min(rr, rrr));
	if (instructions.min_instructions == diff)
		instructions.move = 0;
	else if (instructions.min_instructions == rr)
		instructions.move = 1;
	else if (instructions.min_instructions == rrr)
		instructions.move = 2;
	return (instructions);
}

t_node	*go_to_min_instructions_node(t_stack *b)
{
	int		min_instructions;
	t_node	*ret;
	t_node	*tmp;

	tmp = b->top;
	min_instructions = tmp->instructions.min_instructions;
	ret = tmp;
	while (tmp)
	{
		if (tmp->instructions.min_instructions < min_instructions)
		{
			min_instructions = tmp->instructions.min_instructions;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	push_to_a(t_stack **a, t_stack **b, t_node *tmp)
{
	if (tmp->instructions.move == 0)
	{
		if ()
	}
}


void	sort_all(t_stack **a, t_stack **b)
{
	t_node	*tmp;
	int		index_b;
	int		index_a;
	int		move_b;
	int		move_a;

	tmp = (*a)->top;
	while ((*a)->size > 3)
		pb(a, b, 1);
	sort_three(a);
	while ((*b)->size)
	{
		tmp = (*b)->top;
		while (tmp)
		{
			tmp->instructions = fill_instructions(*a, *b, tmp->data);
			tmp = tmp->next;
		}
		tmp = go_to_min_instructions_node(*b);
		push_to_a(a, b, tmp);
	}
}

		
		