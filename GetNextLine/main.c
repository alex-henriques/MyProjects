/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:41:41 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/28 11:50:42 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("files.txt", O_RDONLY);
	//fd[1] = open("file.txt", O_RDONLY);
	while ((str = get_next_line(1)) != NULL)
	{
		printf("%s\n", str);
		free(str);
	}
	/*while ((str = get_next_line(fd[1])) != NULL)
	{
		printf("%s\n", str);
		free(str);
	}*/
	close(fd);
	//close(fd[1]);
	return (0);
}
