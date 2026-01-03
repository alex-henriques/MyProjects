/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:32:59 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/04 18:21:01 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*newstring(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
	{
		return (ft_strdup(""));
	}
	str = (char *)malloc(len + 1);
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
	{
		return (ft_strdup(""));
	}
	while (trim(set, s1[start]))
	{
		start++;
	}
	while (end > start && trim (set, s1[end -1]))
	{
		end --;
	}
	return (newstring(s1, start, end - start));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strtrim("  ! ! Hello, World!  ", " !"));
	return (0);
}*/
