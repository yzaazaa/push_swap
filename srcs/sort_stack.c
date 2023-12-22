/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:37:45 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 02:45:54 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

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

void	apply_rarrb(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*b)->top->data != to_push->data)
		rrb(b, 1);
	while (index_insert_a(*a, to_push->data))
		ra(a, 1);
	pa(a, b, 1);
}

void	apply_rrarb(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*b)->top->data != to_push->data)
		rb(b, 1);
	while (index_insert_a(*a, to_push->data))
		rra(a, 1);
	pa(a, b, 1);
}

void	apply_rr(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*b)->top->data != to_push->data && index_insert_a(*a, to_push->data))
		rr(a, b, 1);
	while (index_insert_a(*a, to_push->data))
		ra(a, 1);
	while ((*b)->top->data != to_push->data)
		rb(b, 1);
	pa(a, b, 1);
}

void	apply_rrr(t_stack **a, t_stack **b, t_node *to_push)
{
	while ((*b)->top->data != to_push->data && index_insert_a(*a, to_push->data))
		rrr(a, b, 1);
	while (index_insert_a(*a, to_push->data))
		rra(a, 1);
	while ((*b)->top->data != to_push->data)
		rrb(b, 1);
	pa(a, b, 1);
}

void	push_to_a(t_stack **a, t_stack **b, t_node *to_push)
{
	int	index_topush_in_a;
	int	index_topush_in_b;

	index_topush_in_a = index_insert_a(*a, to_push->data);
	index_topush_in_b = get_index(*b, to_push->data);
	if (to_push->instructions.move == 0)
	{
		if (index_topush_in_b < (*b)->size / 2)
			apply_rrarb(a, b, to_push);
		else
			apply_rarrb(a, b, to_push);
	}
	else if (to_push->instructions.move == 1)
		apply_rr(a, b, to_push);
	else if (to_push->instructions.move == 2)
		apply_rrr(a, b, to_push);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size)
		{
			if (list[i] < list[j])
				ft_swap(&list[i], &list[j]);
			j++;
		}
		i++;
	}
}

void	init_chunk_mids(int nb_chunks, int **chunk_mids, t_stack *a)
{
	t_node	*tmp;
	int		*list_sorted;
	int		size;

	tmp = a->top;
	list_sorted = malloc(sizeof(int) * a->size);
	*chunk_mids = malloc(sizeof(int) * nb_chunks);
	size = 0;
	while (tmp)
	{
		list_sorted[size++] = tmp->data;
		tmp = tmp->next;
	}
	sort_int_tab(list_sorted, size);
	if (nb_chunks == 2)
		*chunk_mids[0] = list_sorted[size / 2];
	if (nb_chunks == 3)
	{
		*chunk_mids[0] = list_sorted[size / 3];
		*chunk_mids[1] = list_sorted[size / 3 * 2];
	}
}

void	sort_all(t_stack **a, t_stack **b, int nb_chunks)
{
	t_node	*tmp;
	int		min_index;
	int		min;
	int		*chunk_mids;

	tmp = (*a)->top;
	chunk_mids = NULL;
	init_chunk_mids(nb_chunks, &chunk_mids, *a);
	if (nb_chunks == 1)
	{
		while ((*a)->size > 3)
			pb(a, b, 1);
	}
	if (nb_chunks == 2)
	{
		while ((*b)->size <= (*a)->size)
		{
			if ((*a)->top->data <= chunk_mids[0])
				pb(a, b, 1);
			else
				ra(a, 1);
		}
		while ((*a)->size > 3)
			pb(a, b, 1);
	}
	sort_three(a);
	// print_stack(*a, *b);
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
		// print_stack(*a, *b);
	}
	min_index = get_index(*a, get_min(*a));
	min = get_min(*a);
	if (min_index >= (*a)->size / 2)
		while (min != (*a)->top->data)
			rra(a, 1);
	else
		while (min != (*a)->top->data)
			ra(a, 1);
	// print_stack(*a, *b);
}

		
		