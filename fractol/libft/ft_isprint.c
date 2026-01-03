/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:32:43 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/23 13:58:08 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
		return (0);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	c;

	c = 30;
	printf("%d\n", ft_isprint(c));
	return (0);
}*/
