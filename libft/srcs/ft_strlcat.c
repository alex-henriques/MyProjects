/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:23:35 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/05 12:38:21 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	j_src;

	if (dst == 0 && size == 0)
		return (0);
	i_dst = ft_strlen(dst);
	j_src = ft_strlen(src);
	if (i_dst >= size)
		return (size + j_src);
	if (j_src + i_dst < size)
		ft_memcpy(dst + i_dst, src, (j_src + 1));
	else
	{
		ft_memcpy(dst + i_dst, src, (size - i_dst - 1));
		dst[size - 1] = 0;
	}
	return (i_dst + j_src);
}
