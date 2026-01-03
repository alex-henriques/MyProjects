/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:47 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/04 18:20:30 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (haystack == 0 && len == 0)
		return (0);
	if (*needle == '\0')
	{
		return ((char *) haystack);
	}
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len && needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *) haystack + i);
		}
		i++;
	}
	return (0);
}
