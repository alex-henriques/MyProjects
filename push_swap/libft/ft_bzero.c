/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:46:19 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/25 12:24:53 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}

/*#include <stdio.h>
int	main(void)
{
	char	ptr[15] = "potato is life";

	printf("before bzero: %s\n", ptr);
	ft_bzero(ptr, 4);
	printf("after bzero: %s\n", ptr);
	return (0);
}*/
