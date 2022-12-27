#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 

typedef struct		s_stack
{
	int		content;
	struct s_stack	*next;
	struct s_stack	*previous;
}			t_stack;

t_stack	*ft_new_stack(int content);
void	ft_push(t_stack **stack, t_stack *new);
int	ft_stack_size(t_stack *stack);
int	ft_pop(t_stack **stack);
void	ft_stack_clear(t_stack **stack);
void	ft_print_stack(t_stack *stack);
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
