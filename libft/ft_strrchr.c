/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:00:04 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/19 22:52:46 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			ptr = (char *)(s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		ptr = (char *)(s + i);
	return (ptr);
}
