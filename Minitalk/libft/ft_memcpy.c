/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:26:08 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/25 14:00:02 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_i;
	unsigned char	*dst_j;

	if (src == NULL && dst == NULL)
	{
		return (dst);
	}
	src_i = (unsigned char *) src;
	dst_j = (unsigned char *) dst;
	while (n > 0)
	{
		*dst_j = *src_i;
		src_i++;
		dst_j++;
		n--;
	}
	return (dst);
}
