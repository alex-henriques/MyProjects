/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:26:46 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/30 11:58:40 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	letter;
	size_t			i;

	ptr = (unsigned char *)s;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == letter)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	char	*result = ft_memchr("Hello, World!", 'r', 13);

	printf("Character 'r' %s\n", result ? "found" : "not found");
	return (0);
}*/
