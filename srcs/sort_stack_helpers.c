/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:18:24 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/24 10:13:11 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	pb(a, b, 1);
	pb(a, b, 1);
	while ((*a)->size > 3)
	{
		tmp = (*a)->top;
		while (tmp)
		{
			tmp->instructions = fill_instructions_a(*a, *b, tmp->data);
			tmp = tmp->next;
		}
		tmp = go_to_min_instructions_node(*a);
		push_min_instructions_to_b(a, b, tmp);
	}
	sort_three(a);
}

void	get_min_to_top(t_stack **a)
{
	int	min;
	int	min_index;

	min_index = get_index(*a, get_min(*a));
	min = get_min(*a);
	if (min_index >= (*a)->size / 2)
		while (min != (*a)->top->data)
			rra(a, 1);
	else
		while (min != (*a)->top->data)
			ra(a, 1);
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
