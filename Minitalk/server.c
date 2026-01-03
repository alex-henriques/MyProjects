/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:41:36 by alehenri          #+#    #+#             */
/*   Updated: 2025/02/03 14:21:15 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void	ft_sighandler(int sig)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR2)
		c = (c << 1);
	else if (sig == SIGUSR1)
		c = (c << 1) | 1;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("This is the PID: %d\n", getpid());
	sa.sa_handler = ft_sighandler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	while (1)
		pause();
	return (0);
}
