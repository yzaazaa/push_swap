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
	printf("\n");
	while(stack != NULL)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	printf("\n\n");
}

int	main()
{
	t_stack	*a = ft_new_stack(8);
	t_stack	*b = NULL;

	ft_push(&a, ft_new_stack(5));
	ft_push(&a, ft_new_stack(6));
	ft_push(&a, ft_new_stack(3));
	ft_push(&a, ft_new_stack(1));
	ft_push(&a, ft_new_stack(2));
	printf("init a & b: \n");
	ft_print_stacks(a, b);
	printf("exec sa: \n");
	sa(&a);
	ft_print_stacks(a, b);
	printf("exec pb pb pb: \n");
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	ft_print_stacks(a, b);
	printf("exec ra rb: \n");
	rr(&a, &b);
	ft_print_stacks(a, b);
	printf("exec rra rrb: \n");
	rrr(&a, &b);
	ft_print_stacks(a, b);
	printf("exec sa: \n");
	sa(&a);
	ft_print_stacks(a, b);
	printf("exec pa pa pa: \n");
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	ft_print_stacks(a, b);

	return (0);
}
