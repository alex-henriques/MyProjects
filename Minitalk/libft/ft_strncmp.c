/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:33:52 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/04 18:32:43 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

/*#include <stdio.h>
int	main(void)
{
	const char	str1[] = "hello";
	const char	str2[] = "l";

	printf("%d\n", ft_strncmp(str1, str2, 3));
	return (0);
}*/
