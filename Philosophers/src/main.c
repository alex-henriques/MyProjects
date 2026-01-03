/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:37 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:47:09 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]) != 0)
		{
			printf("Error creating thread for Philosopher %d\n", i + 1);
			cleanup(data);
			return (1);
		}
		i++;
	}
	if (pthread_create(monitor, NULL, monitor_routine, data) != 0)
	{
		printf("Error creating monitor thread\n");
		cleanup(data);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;
	int			i;

	if (parse_arguments(ac, av, &data) != 0)
		return (1);
	if (init_data(&data) != 0)
		return (1);
	if (create_threads(&data, &monitor) != 0)
		return (1);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data.philo_count)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	cleanup(&data);
	return (0);
}
