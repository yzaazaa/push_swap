#include "push_swap.h"

t_stack	*ft_new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->next = NULL;
	new->index = 0;
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
		*stack = new;
		new->index = 0;
		return ;
	}
	tmp = *stack;
	new->next = tmp;
	new->index = (tmp->index) + 1;
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

void	ft_free_stack(t_stack *a)
{
	t_stack	*tmp;

	while(a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	init_stack(t_stack **a, int ac, char **argv)
{
	int	i;
	t_stack	*new;
	int	size;

	i = -1;
	if(ac == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 0;
	size = ft_tab_size(argv) - 1;
	while(size > i)
	{
		new = ft_new_stack(ft_atoi(argv[size]));
		ft_push(a, new);
		size--;
	}
	if(ac == 2)
		ft_free_split(argv, ft_tab_size(argv));
}

int	main(int ac, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	init_stack(&a, ac, argv);
	printf("init a & b: \n");
//	printf("%d", a->content);
//	ft_print_stack(a);

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
	ft_free_stack(a);
	ft_free_stack(b);

	return (0);

}
