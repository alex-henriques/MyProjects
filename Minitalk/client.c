/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:59:13 by alehenri          #+#    #+#             */
/*   Updated: 2025/02/03 14:16:34 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void	ft_sendmessage(int pid, char *msg)
{
	int		i;
	char	c;

	i = 0;
	while (*msg)
	{
		c = *(msg);
		while (i < 8)
		{
			if ((c >> (7 - i)) & 1) 
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(500);
		}
		msg++;
		i = 0;
	}
	i = 0;
	while(i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Not the right number of arguments, lad.\n");
		exit(EXIT_FAILURE);
	}
	else
		ft_sendmessage(ft_atoi(av[1]), av[2]);
	return (0);
}
