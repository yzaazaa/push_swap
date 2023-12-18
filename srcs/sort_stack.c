/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:37:45 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/18 00:27:00 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_till_three(t_stack **a, t_stack **b)
{
	int		i;
	t_node	*tmp;

	while ((*a)->size > 3 && !is_sorted(*a))
	{
		tmp = (*a)->top;
		i = min_operations_ab(*a, *b);
		ft_putstr_fd("i = ", 1);
		ft_putnbr_fd(i, 1);
		ft_putchar_fd('\n', 1);
		while (i >= 0)
		{
			ft_putstr_fd("rarb_count : ", 1);
			ft_putnbr_fd(rarb_count(*a, *b, tmp->data, 'b'), 1);
			ft_putchar_fd('\n', 1);
			ft_putstr_fd("rrarrb_count : ", 1);
			ft_putnbr_fd(rrarrb_count(*a, *b, tmp->data, 'b'), 1);
			ft_putchar_fd('\n', 1);
			ft_putstr_fd("rrarb_count : ", 1);
			ft_putnbr_fd(rrarb_count(*a, *b, tmp->data, 'b'), 1);
			ft_putchar_fd('\n', 1);
			ft_putstr_fd("rarrb_count : ", 1);
			ft_putnbr_fd(rarrb_count(*a, *b, tmp->data, 'b'), 1);
			ft_putchar_fd('\n', 1);
			if (i == rarb_count(*a, *b, tmp->data, 'b'))
			{
				
				ft_putendl_fd("rarb", 1);
				i = rarb_apply(a, b, tmp->data, 'a');
			}
			else if (i == rrarrb_count(*a, *b, tmp->data, 'b'))
			{
				ft_putendl_fd("rrarrb", 1);
				i = rrarrb_apply(a, b, tmp->data, 'a');
			}
			else if (i == rarrb_count(*a, *b, tmp->data, 'b'))
			{
				i = rarrb_apply(a, b, tmp->data, 'a');
				ft_putendl_fd("rarrb", 1);;
			}
			else if (i == rrarb_count(*a, *b, tmp->data, 'b'))
			{
				i = rrarb_apply(a, b, tmp->data, 'a');
				ft_putendl_fd("rrarb", 1);
			}
			else
				tmp = tmp->next;
			ft_putchar_fd('\n', 1);
		}
	}
}

static void	sort_b(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
		pb(a, b, 1);
	if (!is_sorted(*a))
		pb(a, b, 1);
	if (!is_sorted(*a))
		sort_till_three(a, b);
	if (!is_sorted(*a))
		sort_three(a);
}

static void	sort_a(t_stack **a, t_stack **b)
{
	int		i;
	t_node	*tmp;

	while ((*b)->top)
	{
		tmp = (*b)->top;
		i = min_operations_ba(*a, *b);
		while (i >= 0)
		{
			if (i == rarb_count(*a, *b, tmp->data, 'a'))
				i = rarb_apply(a, b, tmp->data, 'b');
			else if (i == rrarrb_count(*a, *b, tmp->data, 'a'))
				i = rrarrb_apply(a, b, tmp->data, 'b');
			else if (i == rarrb_count(*a, *b, tmp->data, 'a'))
				i = rarrb_apply(a, b, tmp->data, 'b');
			else if (i == rrarb_count(*a, *b, tmp->data, 'a'))
				i = rrarb_apply(a, b, tmp->data, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	int	i;

	sort_b(a, b);
	sort_a(a, b);
	i = get_index(*a, get_min(*a));
	if (i < (*a)->size - i)
		while ((*a)->top->data != get_min(*a))
			ra(a, 1);
	else
		while ((*a)->top->data != get_min(*a))
			rra(a, 1);
}
