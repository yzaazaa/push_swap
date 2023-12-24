/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:12:51 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/24 10:37:59 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_instructions
{
	int	move;
	int	min_instructions;
}					t_instructions;

typedef struct s_node
{
	int				data;
	t_instructions	instructions;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}					t_stack;

void	ft_puterr(char *s, t_stack **a, t_stack **b, char **splitted);
void	push(t_stack **stack, int data);
int		pop(t_stack **stack);
void	free_stack(t_stack **stack);
int		in_stack(t_stack *stack, int data);
int		is_sorted(t_stack *stack);
void	init_stacks(t_stack **a, t_stack **b);
int		get_index(t_stack *stack, int data);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		index_insert_b(t_stack *stack, int data);
int		index_insert_a(t_stack *stack, int data);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

#endif