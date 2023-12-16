/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:13:03 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/06 00:55:46 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nb_digits(long n)
{
	int	nbr;

	nbr = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr++;
		n = -n;
	}
	while (n > 0)
	{
		nbr++;
		n /= 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		nbr_digits;
	long	nb;
	char	*ret;

	nb = (long)n;
	nbr_digits = nb_digits(nb);
	ret = malloc(nbr_digits + 1);
	if (!ret)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	ret += nbr_digits;
	*ret = 0;
	if (nb == 0)
		*(--ret) = '0';
	while (nb > 0)
	{
		*(--ret) = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		*(--ret) = '-';
	return (ret);
}

/*
int	main()
{
	int	nbr = -214648;
	printf("%s\n", ft_itoa(nbr));
}
*/
