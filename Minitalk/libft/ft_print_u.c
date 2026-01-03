/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:48:09 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/18 16:11:04 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_print_u(unsigned int n)
{
	int	isdigit;
	int	count;

	count = ft_print_u_count(n);
	if (n >= 10)
	{
		ft_print_u(n / 10);
		ft_print_u(n % 10);
	}
	else if (n < 10)
	{
		isdigit = n + 48;
		write(1, &isdigit, 1);
	}
	return (count);
}
/*
int	main(void)
{
	printf("\n%u\n", ft_print_u(-1));
}*/
