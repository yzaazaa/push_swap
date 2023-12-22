/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:20:02 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 10:25:11 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "parse.h"

int		max(int a, int b);
int		min(int a, int b);
int		init_chunk_mids(t_stack *a);
void	push_to_b(t_stack **a, t_stack **b, int median);
void	get_min_to_top(t_stack **a);
void	apply_rr(t_stack **a, t_stack **b, t_node *to_push);
void	apply_rrr(t_stack **a, t_stack **b, t_node *to_push);
void	apply_diff(t_stack **a, t_stack **b, t_node *to_push);
void	push_to_a(t_stack **a, t_stack **b, t_node *to_push);
void	push_nearest_to_b(t_stack **a, t_stack **b, int chunk_mid);
void	sort_int_tab(int *list, int size);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_all(t_stack **a, t_stack **b);

#endif