/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:28:45 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/30 11:51:24 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	i;

	ptr = NULL;
	i = (char)c;
	while (*s != '\0')
	{
		if (*s == i)
		{
			ptr = (char *)s;
		}
		s++;
	}
	if (i == '\0')
	{
		return ((char *)s);
	}
	return (ptr);
}
/*#include <stdio.h>
int	main(void)
{
	const char	*str = "They're taking the Hobbits to Isengard!";

	printf("test 1: %s\n", ft_strrchr(str, 'o'));
	printf("test 2: %s\n", ft_strrchr(str, 'z'));
	return (0);
}*/
