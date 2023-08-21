/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:55:34 by sbayir            #+#    #+#             */
/*   Updated: 2023/01/20 13:04:12 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_unsigned_len(unsigned int number)
{
	int	len;

	if (number == 0)
		return (1);
	len = 0;
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int number)
{
	char	*num_string;
	int		size;

	size = ft_unsigned_len(number);
	num_string = (char *)malloc(sizeof(char) * size + 1);
	if (!num_string)
		return (0);
	num_string[size] = '\0';
	while (number != 0)
	{
		num_string[size - 1] = number % 10 + 48;
		number = number / 10;
		size--;
	}
	return (num_string);
}

int	ft_print_ui(unsigned int number)
{
	int		len;
	char	*number_string;

	len = 0;
	if (number == 0)
		len = write(1, "0", 1);
	else
	{
		number_string = ft_uitoa(number);
		len = ft_printstr(number_string);
		free (number_string);
	}
	return (len);
}
