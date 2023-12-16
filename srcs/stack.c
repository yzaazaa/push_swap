/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:15:23 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/16 23:44:44 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_node	*create_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push(t_stack **stack, int data)
{
	t_node	*new;

	new = create_node(data);
	if (!new)
		return (free_stack(stack));
	if ((*stack)->size == 0)
	{
		(*stack)->top = new;
		(*stack)->bottom = new;
	}
	else
	{
		new->next = (*stack)->top;
		(*stack)->top->prev = new;
		(*stack)->top = new;
	}
	(*stack)->size++;
}

int	pop(t_stack **stack)
{
	t_node	*tmp;
	int		ret;

	tmp = (*stack)->top;
	ret = tmp->data;
	(*stack)->top = (*stack)->top->next;
	if ((*stack)->top == NULL)
		(*stack)->bottom = NULL;
	else
		(*stack)->top->prev = NULL;
	(*stack)->size--;
	free(tmp);
	return (ret);
}

void	free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	while ((*stack)->top)
		pop(stack);
	free(*stack);
	*stack = NULL;
}

void	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	(*a)->top = NULL;
	(*a)->bottom = NULL;
	(*a)->size = 0;
	*b = malloc(sizeof(t_stack));
	(*b)->top = NULL;
	(*b)->bottom = NULL;
	(*b)->size = 0;
}
