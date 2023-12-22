/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:08:15 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 02:46:41 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->size == 2)
		sort_two(a);
	else if ((*a)->size == 3)
		sort_three(a);
	else if ((*a)->size == 4)
		sort_four(a, b);
	else if ((*a)->size == 5)
		sort_five(a, b);
	else
		sort_all(a, b, 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(1);
	init_stacks(&a, &b);
	parse_args(&a, ac, av);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
