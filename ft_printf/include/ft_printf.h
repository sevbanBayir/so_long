/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:07:23 by sbayir            #+#    #+#             */
/*   Updated: 2023/01/18 20:10:27 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
void	ft_put_hex(unsigned int number, const char format);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long ptr);
void	ft_put_ptr(unsigned long num);
int		ft_ptr_len(unsigned long num);
int		ft_printnbr(int n);
int		ft_print_ui(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);
int		ft_unsigned_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);
char	*ft_uitoa(unsigned int n);

#endif
