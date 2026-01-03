/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:30:54 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/30 11:53:46 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
/*#include <stdio.h>
int	main(void)
{
	const char	*str = "We're taking the Hobbits to Eisengard";

	printf("test 1: %s\n", ft_strchr(str, 'o'));
	printf("test 2: %s\n", ft_strchr(str, 'z'));
	printf("test 3: %s\n", ft_strchr(str, '\0'));
	return (0);
}*/
