/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:20:02 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/18 00:13:55 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "parse.h"

int		rrarrb_count(t_stack *a, t_stack *b, int data, char c);
int		rrarb_count(t_stack *a, t_stack *b, int data, char c);
int		rarrb_count(t_stack *a, t_stack *b, int data, char c);
int		rarb_count(t_stack *a, t_stack *b, int data, char c);
int		rarb_apply(t_stack **a, t_stack **b, int data, char c);
int		rrarrb_apply(t_stack **a, t_stack **b, int data, char c);
int		rrarb_apply(t_stack **a, t_stack **b, int data, char c);
int		rarrb_apply(t_stack **a, t_stack **b, int data, char c);

int		min_operations_ab(t_stack *a, t_stack *b);
int		min_operations_ba(t_stack *a, t_stack *b);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_all(t_stack **a, t_stack **b);

#endif