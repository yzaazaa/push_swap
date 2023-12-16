/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:06:00 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/04 20:47:43 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	if (!dst && dstsize == 0)
	{
		return (ft_strlen(src));
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	dstsize = dstsize - dst_len;
	if (dstsize)
	{
		while (src[i] && dstsize - 1 != 0)
		{
			dst[dst_len + i] = src[i];
			i++;
			dstsize--;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
