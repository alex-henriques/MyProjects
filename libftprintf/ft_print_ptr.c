/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:23:56 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/15 16:03:05 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		count += write(1, "0x", 2);
		count += ft_print_hex((unsigned long long)ptr, 16, 10);
	}
	return (count);
}
