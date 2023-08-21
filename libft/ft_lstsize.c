/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:34:11 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/20 02:12:37 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		i;

	ptr = lst;
	if (!ptr)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
