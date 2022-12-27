#include "push_swap.h"

t_stack	*ft_new_stack(int content)
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
	new->next = tmp;
	tmp->previous = new;
	*stack = new;
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

int	ft_pop(t_stack **stack)
{
	t_stack *tmp;
	int	ret;

	tmp = *stack;
	*stack = (*stack)->next;
	if(tmp->next != NULL)
		tmp->next->previous = NULL;
	tmp->next = NULL;
	ret = tmp->content;
	free(tmp);
	return (ret);
}

void	ft_stack_clear(t_stack **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	while(size--)
		ft_pop(stack);
	*stack = NULL;
}

void	ft_print_stack(t_stack *stack)
{
	if(!stack)
	{
		printf("NULL\n");
		return ;
	}
	while(stack->next != NULL)
		stack = stack->next;
	while(stack != NULL)
	{
		printf("%d ", stack->content);
		stack = stack->previous;
	}
	printf("\n");
}
/*
int	main()
{
	t_stack	*b = ft_new_stack(1);
	t_stack	*a = ft_new_stack(7);

	ft_push(&b, ft_new_stack(2));
	ft_push(&b, ft_new_stack(3));
	ft_push(&b, ft_new_stack(4));
	ft_push(&b, ft_new_stack(5));
	ft_push(&b, ft_new_stack(6));
	printf("b: ");
	ft_print_stack(b);

	ft_push(&a, ft_new_stack(8));
	ft_push(&a, ft_new_stack(9));
	ft_push(&a, ft_new_stack(10));
	ft_push(&a, ft_new_stack(11));
	ft_push(&a, ft_new_stack(12));
	printf("a: ");
	ft_print_stack(a);
	rrr(&a, &b);
	printf("a: ");
	ft_print_stack(a);
	printf("b: ");
	ft_print_stack(b);

	return (0);
}*/
