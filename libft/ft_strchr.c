/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:33:49 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/19 20:54:03 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if (!(char)c)
		return ((char *)(s));
	return (NULL);
}
