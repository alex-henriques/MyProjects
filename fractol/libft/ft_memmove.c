/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:00:41 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/30 12:11:29 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dest == 0 && src == 0)
		return (0);
	d = (char *) dest;
	s = (char *) src;
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (i++ < n)
		{
			d[i - 1] = s[i - 1];
		}
	}
	return (dest);
}
