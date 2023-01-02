#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (ft_stack_size(*stack_a) == 2)
	{
		sa(stack_a);
		write(1, "sa\n", 3);
	}
	else
		sort(stack_a, stack_b, len);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (argc < 2)
		return (0);
	check_args(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argc, argv);
	len = ft_stack_size(stack_a);
	if (stack_is_sorted(&stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	//ft_print_stacks(stack_a, stack_b);
	sort_stack(&stack_a, &stack_b, len);
	//ft_print_stacks(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
