/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:34:44 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/16 23:44:31 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	ra(t_stack **a, int print)
{
	t_node	*new_bottom;

	if ((*a)->size > 2)
	{
		new_bottom = (*a)->top;
		(*a)->top = (*a)->top->next;
		(*a)->top->prev = NULL;
		new_bottom->next = NULL;
		(*a)->bottom->next = new_bottom;
		new_bottom->prev = (*a)->bottom;
		(*a)->bottom = new_bottom;
		if (print == 1)
			ft_putendl_fd("ra", 1);
	}
}

void	rb(t_stack **b, int print)
{
	t_node	*new_bottom;

	if ((*b)->size > 2)
	{
		new_bottom = (*b)->top;
		(*b)->top = (*b)->top->next;
		(*b)->top->prev = NULL;
		new_bottom->next = NULL;
		(*b)->bottom->next = new_bottom;
		new_bottom->prev = (*b)->bottom;
		(*b)->bottom = new_bottom;
		if (print == 1)
			ft_putendl_fd("rb", 1);
	}
}

void	rr(t_stack **a, t_stack **b, int print)
{
	if (print == 1)
		ft_putendl_fd("rr", 1);
	ra(a, 0);
	rb(b, 0);
}

void	rra(t_stack **a, int print)
{
	t_node	*new_top;

	if ((*a)->size > 2)
	{
		new_top = (*a)->bottom;
		(*a)->bottom = new_top->prev;
		(*a)->bottom->next = NULL;
		new_top->prev = NULL;
		new_top->next = (*a)->top;
		(*a)->top->prev = new_top;
		(*a)->top = new_top;
		if (print == 1)
			ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_stack **b, int print)
{
	t_node	*new_top;

	if ((*b)->size > 2)
	{
		new_top = (*b)->bottom;
		(*b)->bottom = new_top->prev;
		(*b)->bottom->next = NULL;
		new_top->prev = NULL;
		new_top->next = (*b)->top;
		(*b)->top->prev = new_top;
		(*b)->top = new_top;
		if (print == 1)
			ft_putendl_fd("rrb", 1);
	}
}
