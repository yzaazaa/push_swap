/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:06:19 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/06 00:13:31 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ncell;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	ret = 0;
	while (lst)
	{
		content = f(lst->content);
		ncell = ft_lstnew(content);
		if (!ncell)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, ncell);
		lst = lst->next;
	}
	return (ret);
}
