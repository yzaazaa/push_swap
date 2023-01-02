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
	if(!stack_is_sorted(a))
		sa(a);
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

	save.i = 0;
	while(save.i < 31)
	{
		save.k = 0;
		positive_sort(a, b, &save, len);
		save.i++;
	}
}
