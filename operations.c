#include "push_swap.h"

void sa(t_stack **a)
{
	int	size_a;
	t_stack	*first_node;
	t_stack	*second_node;

	size_a = ft_stack_size(*a);
	if(size_a < 2)
		return ;
	second_node = ft_copy_stack(*a);
	ft_pop(a);
	first_node = ft_copy_stack(*a);
	ft_pop(a);
	ft_push(a, second_node);
	ft_push(a, first_node);
}

void sb(t_stack **b)
{
	int	size_b;
	t_stack	*first_node;
	t_stack	*second_node;

	size_b = ft_stack_size(*b);
	if(size_b < 2)
		return ;
	second_node = ft_copy_stack(*b);
	ft_pop(b);
	first_node = ft_copy_stack(*b);
	ft_pop(b);
	ft_push(b, second_node);
	ft_push(b, first_node);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack *new;
	if(!b || !*b)
		return ;
	new = ft_copy_stack(*b);
	ft_push(a, new);
	ft_pop(b);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *new;
	if(!a || !*a)
		return ;
	new = ft_copy_stack(*a);
	ft_push(b, new);
	ft_pop(a);
}

void	rra(t_stack **a, t_stack **b)
{
	int	size_a;
	int	count;
	t_stack *first_node;

	count = 0;
	size_a = ft_stack_size(*a);
	if(size_a <= 1)
		return ;
	while(size_a > 1)
	{
		pb(a, b);
		size_a--;
		count++;
	}
	first_node = ft_copy_stack(*a);
	ft_pop(a);
	while(count--)
		pa(a, b);
	ft_push(a, first_node);
}

void	rrb(t_stack **a, t_stack **b)
{
	int	count;
	int	size_b;
	t_stack *first_node;

	count = 0;
	size_b = ft_stack_size(*b);
	if(size_b <= 1)
		return ;
	while(size_b > 1)
	{
		pa(a, b);
		size_b--;
		count++;
	}
	first_node = ft_copy_stack(*b);
	ft_pop(b);
	while(count--)
		pb(a, b);
	ft_push(b, first_node);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
}

void	ra(t_stack **a, t_stack **b)
{
	int	count;
	int	size_a;
	t_stack *last_node;

	count = 0;
	size_a = ft_stack_size(*a);
	if(size_a <= 1)
		return ;
	last_node = ft_copy_stack(*a);
	ft_pop(a);
	size_a--;
	while(size_a > 0)
	{
		pb(a, b);
		size_a--;
		count++;
	}
	ft_push(a, last_node);
	while(count--)
		pa(a, b);
}

void	rb(t_stack **a, t_stack **b)
{
	int	count;
	int	size_b;
	t_stack *last_node;

	count = 0;
	size_b = ft_stack_size(*b);
	if(size_b <= 1)
		return ;
	last_node = ft_copy_stack(*b);
	ft_pop(b);
	size_b--;
	while(size_b > 0)
	{
		pa(a, b);
		size_b--;
		count++;
	}
	ft_push(b, last_node);
	while(count--)
		pb(a, b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;
	int	max;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	if(size_a >= size_b)
		max = size_a;
	else
		max = size_b;
	printf("\n");
	while(max--)
	{
		if(!a)
			printf(" ");
		else if(a != NULL)
		{
			printf("%d ", a->content);
			a = a->next;
		}
		if(!b)
			printf("\n");
		else if(b != NULL)
		{
			printf("%d\n", b->content);
			b = b->next;
		}
	}
	printf("- -\na b\n");
}
