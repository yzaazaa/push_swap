/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:18:24 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 11:52:43 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int median)
{
	int	size_a;

	size_a = (*a)->size;
	while ((*b)->size <= size_a / 2)
		push_nearest_to_b(a, b, median);
	while ((*a)->size > 3)
		pb(a, b, 1);
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
