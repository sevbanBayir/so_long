/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:12 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/20 00:32:44 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newnode;

	newhead = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode)
			ft_lstadd_back(&newhead, newnode);
		else
			ft_lstclear(&newhead, del);
		lst = lst->next;
	}
	return (newhead);
}
