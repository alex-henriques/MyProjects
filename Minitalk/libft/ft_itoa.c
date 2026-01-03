/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:40:58 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/04 19:03:35 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length++;
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;

	length = nbrlen(n);
	result = ft_calloc((length + 1), sizeof(char));
	if (!result)
		return (0);
	if (n == -2147483648)
	{
		result[--length] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	else if (n == 0)
		result [0] = '0';
	while (n > 0)
	{
		result[length-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
