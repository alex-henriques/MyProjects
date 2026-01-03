/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:57 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/18 16:34:04 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_print_str(const char *str);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_format(char spec, va_list ap);
int	ft_print_hex(unsigned long long n, int base, int uppercase);
int	ft_print_digit(int n);
int	ft_print_u(unsigned int n);

#endif
