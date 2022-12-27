#include "push_swap.h"

void sa(t_stack **a, t_stack **b)
{
	int	size_a;
	int	first;
	int	second;
	int	count;

	count = 0;
	size_a = ft_stack_size(*a);
	if(size_a < 3)
		return ;
	while(size_a > 2)
	{
		ft_push(b, ft_new_stack(ft_pop(a)));
		size_a--;
		count++;
	}
	first = ft_pop(a);
	second = ft_pop(a);
	while(count--)
		ft_push(a, ft_new_stack(ft_pop(b)));
	ft_push(a, ft_new_stack(second));
	ft_push(a, ft_new_stack(first));
}

void sb(t_stack **a, t_stack **b)
{
	int	count;
	int	first;
	int	second;
	int	size_b;

	count = 0;
	size_b = ft_stack_size(*b);
	if(size_b < 3)
		return ;
	while(size_b > 2)
	{
		ft_push(a, ft_new_stack(ft_pop(b)));
		size_b--;
		count++;
	}
	first = ft_pop(b);
	second = ft_pop(b);
	while(count--)
		ft_push(b, ft_new_stack(ft_pop(a)));
	ft_push(b, ft_new_stack(second));
	ft_push(b, ft_new_stack(first));
}

void	pa(t_stack **a, t_stack **b)
{
	if(!b || !*b)
		return ;
	ft_push(a, ft_new_stack(ft_pop(b)));
}

void	pb(t_stack **a, t_stack **b)
{
	if(!a || !*a)
		return ;
	ft_push(b, ft_new_stack(ft_pop(a)));
}

void	ra(t_stack **a, t_stack **b)
{
	int	first;
	int	size_a;
	int	count;

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
	first = ft_pop(a);
	while(count--)
		pa(a, b);
	ft_push(a, ft_new_stack(first));
}

void	rb(t_stack **a, t_stack **b)
{
	int	first;
	int	count;
	int	size_b;

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
	first = ft_pop(b);
	while(count--)
		pb(a, b);
	ft_push(b, ft_new_stack(first));
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_stack **a, t_stack **b)
{
	int	last;
	int	count;
	int	size_a;

	count = 0;
	size_a = ft_stack_size(*a);
	if(size_a <= 1)
		return ;
	last = ft_pop(a);
	size_a--;
	while(size_a > 0)
	{
		pb(a, b);
		size_a--;
		count++;
	}
	ft_push(a, ft_new_stack(last));
	while(count--)
		pa(a, b);
}

void	rrb(t_stack **a, t_stack **b)
{
	int	last;
	int	count;
	int	size_b;

	count = 0;
	size_b = ft_stack_size(*b);
	if(size_b <= 1)
		return ;
	last = ft_pop(b);
	size_b--;
	while(size_b > 0)
	{
		pa(a, b);
		size_b--;
		count++;
	}
	ft_push(b, ft_new_stack(last));
	while(count--)
		pb(a, b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
}
