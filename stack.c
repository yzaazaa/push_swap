#include "push_swap.h"

t_stack	*ft_new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->next = NULL;
	new->index = -1;
	new->content = content;
	return (new);
}

t_stack	*ft_copy_stack(t_stack *stack)
{
	t_stack *ret;

	ret = ft_new_stack(stack->content);
	ret->index = stack->index;
	return (ret);
}

void	ft_push(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if(!stack)
		return ;
	if(!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	new->next = tmp;
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

t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
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
	index_stack(a);
	if(ac == 2)
		ft_free(argv);
}