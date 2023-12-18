/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:12:51 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/17 02:03:54 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->top->data > (*a)->bottom->data)
		sa(a, 1);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->top->data;
	second = (*a)->top->next->data;
	third = (*a)->bottom->data;
	if (first > second && first < third && second < third)
		sa(a, 1);
	else if (first > second && first > third && second < third)
		ra(a, 1);
	else if (first > second && first > third && second > third)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (first < second && first < third && second > third)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (first < second && first > third && second > third)
		rra(a, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	if ((*a)->top->data == min)
		pb(a, b, 1);
	else if ((*a)->top->next->data == min)
	{
		sa(a, 1);
		pb(a, b, 1);
	}
	else if ((*a)->bottom->data == min)
	{
		rra(a, 1);
		pb(a, b, 1);
	}
	else
	{
		rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
	sort_three(a);
	pa(a, b, 1);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int min)
{
	if ((*a)->top->data == min)
		pb(a, b, 1);
	else if ((*a)->top->next->data == min)
	{
		sa(a, 1);
		pb(a, b, 1);
	}
	else if ((*a)->bottom->data == min)
	{
		rra(a, 1);
		pb(a, b, 1);
	}
	else if ((*a)->bottom->prev->data == min)
	{
		rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
	else
	{
		rra(a, 1);
		rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	push_min_to_b(a, b, min);
	sort_four(a, b);
	pa(a, b, 1);
}
