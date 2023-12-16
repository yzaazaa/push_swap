/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:05:29 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/16 23:44:25 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	sa(t_stack **a, int print)
{
	int	tmp;

	if (print == 1)
		ft_putendl_fd("sa", 1);
	if ((*a)->size < 2)
		return ;
	tmp = (*a)->top->data;
	(*a)->top->data = (*a)->top->next->data;
	(*a)->top->next->data = tmp;
}

void	sb(t_stack **b, int print)
{
	int	tmp;

	if (print == 1)
		ft_putendl_fd("sb", 1);
	if ((*b)->size < 2)
		return ;
	tmp = (*b)->top->data;
	(*b)->top->data = (*b)->top->next->data;
	(*b)->top->next->data = tmp;
}

void	ss(t_stack **a, t_stack **b, int print)
{
	if (print == 1)
		ft_putendl_fd("ss", 1);
	sa(a, 0);
	sb(b, 0);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	if (print == 1)
		ft_putendl_fd("pa", 1);
	if (!*b)
		return ;
	push(a, pop(b));
}

void	pb(t_stack **a, t_stack **b, int print)
{
	if (print == 1)
		ft_putendl_fd("pb", 1);
	if (!*a)
		return ;
	push(b, pop(a));
}
