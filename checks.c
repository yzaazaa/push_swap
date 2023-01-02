#include "push_swap.h"

int	is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;	

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			return ;
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!isnum(argv[i]) || is_repeat(tmp, argv, i) || !*argv[i])
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		tmp = ft_atol(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}