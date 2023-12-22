/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:37:45 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 10:25:05 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_instructions	fill_instructions(t_stack *a, t_stack *b, int data)
{
	int				index_b;
	int				index_a;
	int				move[3];
	t_instructions	instructions;

	index_a = index_insert_a(a, data);
	index_b = get_index(b, data);
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

static t_node	*go_to_min_instructions_node(t_stack *b)
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

static int	get_median(t_stack *a)
{
	t_node	*tmp;
	int		*list_sorted;
	int		size;
	int		ret;

	tmp = a->top;
	list_sorted = malloc(sizeof(int) * a->size);
	size = 0;
	while (tmp)
	{
		list_sorted[size++] = tmp->data;
		tmp = tmp->next;
	}
	sort_int_tab(list_sorted, size);
	ret = list_sorted[size / 2];
	free(list_sorted);
	return (ret);
}

void	push_nearest_to_b(t_stack **a, t_stack **b, int chunk_mid)
{
	int		from_top;
	int		from_bottom;
	t_node	*tmp;

	tmp = (*a)->top;
	from_top = 0;
	while (tmp && tmp->data > chunk_mid)
	{
		from_top++;
		tmp = tmp->next;
	}
	from_bottom = 0;
	tmp = (*a)->bottom;
	while (tmp && tmp->data > chunk_mid)
	{
		from_bottom++;
		tmp = tmp->prev;
	}
	if (from_bottom <= from_top)
		while ((*a)->top->data > chunk_mid)
			rra(a, 1);
	else
		while ((*a)->top->data > chunk_mid)
			ra(a, 1);
	pb(a, b, 1);
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_node	*tmp;
	int		median;

	median = get_median(*a);
	push_to_b(a, b, median);
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
	get_min_to_top(a);
}
