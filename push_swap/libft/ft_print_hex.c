/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:16:02 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/15 16:02:01 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned long long n, int base, int uppercase)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (uppercase == 88)
		symbols = "0123456789ABCDEF";
	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	if (n < (unsigned long long)base)
		count += write(1, &symbols[n], 1);
	else
	{
		count = ft_print_hex(n / base, base, uppercase);
		count += ft_print_hex(n % base, base, uppercase);
	}
	return (count);
}
