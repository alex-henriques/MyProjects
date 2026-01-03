/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:55:14 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/15 16:03:46 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (spec == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (spec == 'd' || spec == 'i')
		count += ft_print_digit(va_arg(ap, int));
	else if (spec == 'x' || spec == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), 16, spec);
	else if (spec == '%')
		count += write(1, "%", 1);
	else if (spec == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (spec == 'u')
		count += ft_print_u(va_arg(ap, unsigned int));
	else
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
