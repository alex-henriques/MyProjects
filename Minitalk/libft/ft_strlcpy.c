/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:27:42 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/30 11:50:01 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	source;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	source = i;
	if (dstsize != 0)
	{
		j = 0;
		while (j < dstsize -1 && src[j] != '\0')
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (source);
}

/*#include <stdio.h>
int	main(void)
{
	char	src[] = "Hello World!";
	char	dst[6];

	ft_strlcpy(dst, src, sizeof(dst));
	printf("Destination: %s\n", dst);
	return (0);
}*/
