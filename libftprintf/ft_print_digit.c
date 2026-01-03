/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:10:53 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/18 16:32:00 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_print_digit(int n)
{
	int	isdigit;
	int	counter;

	counter = ft_print_count(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_digit(n / 10);
		ft_print_digit(n % 10);
	}
	else if (n < 10)
	{
		isdigit = n + 48;
		write(1, &isdigit, 1);
	}
	return (counter);
}
