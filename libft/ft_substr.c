/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:32:24 by sbayir            #+#    #+#             */
/*   Updated: 2022/12/20 02:13:22 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	size_t			i;
	size_t			j;
	char			*substr;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
		substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (0);
	i = start;
	j = 0;
	while (s[i] && j < len)
		substr[j++] = s[i++];
	substr[j] = 0;
	return (substr);
}
