#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 

typedef struct		s_stack
{
	void		*content;
	struct s_stack	*next;
	struct s_stack	*previous;
}			t_stack;

t_stack	*ft_new_stack(void *content);
void	ft_push(t_stack **stack, t_stack *new);
int	ft_stack_size(t_stack *stack);
void	ft_pop(t_stack **stack);
void	ft_stack_clear(t_stack **stack);
void	ft_print_stack(t_stack *stack);

#endif
