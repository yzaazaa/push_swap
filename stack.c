#include "push_swap.h"

t_stack	*ft_new_stack(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->previous = NULL;;
	new->next = NULL;
	new->content = content;
	return (new);
}

void	ft_push(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if(!stack)
		return ;
	if(!*stack)
	{
		new->previous = NULL;
		*stack = new;
		return ;
	}
	tmp = *stack;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	if(!stack)
		return (0);
	size = 1;
	while(stack->next != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	ft_pop(t_stack **stack)
{
	t_stack	*tmp;

	if(!*stack || !stack)
		return ;
	tmp = *stack;
	while(tmp->next != NULL)
		tmp = tmp->next;
	if(tmp->previous != NULL)
		tmp->previous->next = tmp->next;
	free(tmp);
}

void	ft_stack_clear(t_stack **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	while(size--)
		ft_pop(stack);
}

void	ft_print_stack(t_stack *stack)
{
	while(stack != NULL)
	{
		printf("%d, ", (int)stack->content);
		stack = stack->next;
	}
	printf("\n");
}
