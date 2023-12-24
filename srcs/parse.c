/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:00:04 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/24 10:37:37 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int	is_integer(char *str, t_stack *a, t_stack *b, char **splitted)
{
	int		i;
	int		sign;
	long	res;
	long	tmp;

	i = 0;
	res = 0;
	sign = check_sign(str, &i);
	if (str[i] == '\0')
		ft_puterr("Error", &a, &b, splitted);
	if (!ft_strcmp("-2147483648", str))
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = (res * 10) + (str[i] - '0');
		if (tmp > INT_MAX)
			return (0);
		res = tmp;
		i++;
	}
	return (str[i] == '\0');
}

static int	in_splitted(char **splitted, char *str, int index)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		if (i != index && !ft_strcmp(splitted[i], str))
			return (1);
		i++;
	}
	return (0);
}

static char	**check(char *arg, t_stack *a, t_stack *b)
{
	char	**splitted;
	int		i;

	if (!arg[0])
		ft_puterr("Error", &a, &b, NULL);
	splitted = ft_split(arg, ' ');
	if (!splitted)
		ft_puterr("Error", &a, &b, splitted);
	i = 0;
	if (!splitted[i])
		ft_puterr("Error", &a, &b, splitted);
	while (splitted[i])
	{
		if (!is_integer(splitted[i], a, b, splitted))
			ft_puterr("Error", &a, &b, splitted);
		if (in_splitted(splitted, splitted[i], i)
			|| in_stack(a, ft_atoi(splitted[i])))
			ft_puterr("Error", &a, &b, splitted);
		i++;
	}
	return (splitted);
}

void	parse_args(t_stack **a, t_stack **b, int ac, char **av)
{
	char	**splitted;
	int		i;

	ac--;
	splitted = NULL;
	while (ac)
	{
		splitted = check(av[ac], *a, *b);
		i = 0;
		while (splitted[i])
			i++;
		i--;
		while (i >= 0)
		{
			push(a, ft_atoi(splitted[i--]));
			if (!(*a))
				ft_puterr("Error", a, b, splitted);
		}
		ac--;
		ft_free(splitted);
	}
}

void	check_line(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else
		ft_puterr("Error", a, b, NULL);
}
