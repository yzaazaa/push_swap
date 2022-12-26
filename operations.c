#include "push_swap.h"

void sa(t_stack **a, t_stack **b)
{
	int	size_a;
	int	first;
	int	second;
	int	size_b;

	size_a = ft_stack_size(*a);
	if(size_a < 3)
		return ;
	while(size_a > 2)
	{
		ft_push(b, ft_new_stack(ft_pop(a)));
		size_a--;
	}
	first = ft_pop(a);
	second = ft_pop(a);
	size_b = ft_stack_size(*b);
	while(size_b--)
		ft_push(a, ft_new_stack(ft_pop(b)));
	ft_push(a, ft_new_stack(second));
	ft_push(a, ft_new_stack(first));
}

void sb(t_stack **a, t_stack **b)
{
	int	size_a;
	int	first;
	int	second;
	int	size_b;

	size_b = ft_stack_size(*b);
	if(size_b < 3)
		return ;
	while(size_b > 2)
	{
		ft_push(a, ft_new_stack(ft_pop(b)));
		size_b--;
	}
	first = ft_pop(b);
	second = ft_pop(b);
	size_a = ft_stack_size(*a);
	while(size_a--)
		ft_push(b, ft_new_stack(ft_pop(a)));
	ft_push(b, ft_new_stack(second));
	ft_push(b, ft_new_stack(first));
}
