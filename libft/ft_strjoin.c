/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:19:39 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/20 02:13:04 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	iterator;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	iterator = 0;
	j = 0;
	while (s1[iterator])
		*(str + j++) = s1[iterator++];
	iterator = 0;
	while (s2[iterator])
		*(str + j++) = s2[iterator++];
	str[j] = 0;
	return (str);
}
*/
