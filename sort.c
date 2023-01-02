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

void	sort_two(t_stack **a, t_stack **b)
{
	if(!stack_is_sorted(a))
		sa(a);
}