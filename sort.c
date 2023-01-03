#include "push_swap.h"

int		stack_is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_two(t_stack **a)
{
	if(stack_is_sorted(a))
		return ;
	sa(a);
	write(1, "sa\n", 3);
}

void	sort_three(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

	if(stack_is_sorted(a))
		return ;
	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;

	if(first > second && first < third && second < third)
	{
		sa(a);
		write(1, "sa\n", 3);
		return ;
	}
	if(first > second && first > third && second > third)
	{
		sa(a);
		write(1, "sa\n", 3);
		rra(a, b);
		write(1, "rra\n", 4);
		return ;
	}
	if(first > second && first > third && second < third)
	{
		ra(a, b);
		write(1, "ra\n", 3);
		return ;
	}
	if(first < second && first < third && second > third)
	{
		sa(a);
		write(1, "sa\n", 3);
		ra(a, b);
		write(1, "ra\n", 4);
		return ;
	}
	if(first < second && first > third && second > third)
	{
		rra(a, b);
		write(1, "rra\n", 4);
		return ;
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	first_a;
	int	second_a;
	int	third_a;
	int content_b;

	if(stack_is_sorted(a))
		return ;
	pb(a, b);
	write(1, "pb\n", 3);
	sort_three(a, b);
	first_a = (*a)->content;
	second_a = (*a)->next->content;
	third_a = (*a)->next->next->content;
	content_b = (*b)->content;
	if(content_b < first_a)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		return ;
	}
	if(content_b > third_a)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		ra(a, b);
		write(1, "ra\n", 3);
		return ;
	}
	if(content_b > first_a && content_b < second_a)
	{
		ra(a, b);
		write(1, "ra\n", 3);
		pa(a, b);
		write(1, "pa\n", 3);
		rra(a, b);
		write(1, "rra\n", 4);
		return ;
	}
	if(content_b > second_a && content_b < third_a)
	{
		ra(a, b);
		write(1, "ra\n", 4);
		ra(a, b);
		write(1, "ra\n", 4);
		pa(a, b);
		write(1, "pa\n", 4);
		rra(a, b);
		write(1, "rra\n", 4);
		rra(a, b);
		write(1, "rra\n", 4);
		return ;
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	first_a;
	int	last_a;
	int	count;

	int content_b;

	if(stack_is_sorted(a))
		return ;
	pb(a, b);
	write(1, "pb\n", 3);
	content_b = (*b)->content;
	sort_four(a, b);
	first_a = (*a)->content;
	last_a = (*a)->next->next->next->content;
	if(content_b < first_a)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		return ;
	}
	if(content_b > last_a)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		ra(a, b);
		write(1, "ra\n", 3);
		return ;
	}
	count = 0;
	while((*a)->content < content_b)
	{
		ra(a, b);
		write(1, "ra\n", 3);
		count++;
	}
	pa(a, b);
	write(1, "pa\n", 3);
	while(count--)
		rra(a, b);
}

void	positive_sort(t_stack **a, t_stack **b, t_save *save, int len)
{
	int	j;

	j = 0;
	while(j < len)
	{
		if(((*a)->index >> save->i) & 1)
		{
			pb(a, b);
			write(1, "pb\n", 3);
			rb(a, b);
			write(1, "rb\n", 3);
			save->k++;
		}
		else
		{
			ra(a, b);
			write(1, "ra\n", 3);
		}
		j++;
	}
	j = 0;
	if(b != NULL)
	{
		while(j < save->k)
		{
			pa(a, b);
			write(1, "pa\n", 3);
			ra(a, b);
			write(1, "ra\n", 3);
			j++;
		}
	}
}

void	sort(t_stack **a, t_stack **b, int len)
{
	t_save save;

	if(len == 2)
		sort_two(a);
	else if(len == 3)
		sort_three(a, b);
	else if(len == 4)
		sort_four(a, b);
	else if(len == 5)
		sort_five(a, b);
	else
	{
		save.i = 0;
		while(save.i < 31)
		{
			save.k = 0;
			positive_sort(a, b, &save, len);
			save.i++;
		}
	}
}
