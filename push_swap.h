#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 

typedef struct		s_stack
{
	int		content;
	int		index;
	struct s_stack	*next;
}			t_stack;

typedef struct		s_save
{
	int	i;
	int	k;
}			t_save;

t_stack	*ft_new_stack(int content);
t_stack	*ft_copy_stack(t_stack *stack);
void	ft_push(t_stack **stack, t_stack *new);
int	ft_stack_size(t_stack *stack);
int	ft_pop(t_stack **stack);
void	ft_stack_clear(t_stack **stack);
void	ft_print_stack(t_stack *stack);
void	ft_print_stacks(t_stack *a, t_stack *b);
void	init_stack(t_stack **a, int ac, char **argv);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ft_free_stack(t_stack *a);
int	ft_atoi(const char *nptr);
long long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
int	ft_tab_size(char **tab);
void	ft_free(char **str);
int	ft_isdigit(int c);
int	stack_is_sorted(t_stack **stack);
void	sort(t_stack **a, t_stack **b, int len);
void	check_args(int argc, char **argv);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
#endif
