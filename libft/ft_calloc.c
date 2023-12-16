/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:39:50 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/02 22:49:59 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	size_t			i;
	size_t			final_size;
	unsigned char	*bytes;

	final_size = count * size;
	ret = malloc(final_size);
	if (!ret)
		return (NULL);
	bytes = (unsigned char *)ret;
	i = 0;
	while (i < final_size)
		bytes[i++] = 0;
	return (ret);
}
