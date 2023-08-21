/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:30:16 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/20 00:30:40 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap;

	if (!(*(lst)))
		return ;
	while (*lst)
	{
		swap = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = swap;
	}
}
