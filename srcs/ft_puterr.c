/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:42:00 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 10:59:03 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_puterr(char *s, t_stack **a, t_stack **b, char **splitted)
{
	if (splitted)
		ft_free(splitted);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_putendl_fd(s, 2);
	exit(0);
}
