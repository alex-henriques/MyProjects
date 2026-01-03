/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:31:56 by alehenri          #+#    #+#             */
/*   Updated: 2024/10/30 11:57:35 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	i = count * size;
	if (count != 0 && size != 0 && i / size != count)
		return (0);
	temp = malloc(i);
	ptr = temp;
	if (temp == 0)
	{
		return (0);
	}
	while (j < i)
	{
		ptr[j] = 0;
		j++;
	}
	return (temp);
}

/*#include <stdio.h>
int	main(void)
{
	int	*arr;

	arr = ft_calloc(5, sizeof(int));
	printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	return (0);
}*/
