/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:30 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:36:59 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (1);
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].data = data;
		i++;
	}
}

int	init_data(t_data *data)
{
	data->start_time = get_time();
	data->someone_died = 0;
	data->all_ate_enough = 0;
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	if (init_mutexes(data) != 0)
	{
		printf("Error: Mutex initialization failed\n");
		free(data->philos);
		return (1);
	}
	init_philo(data);
	return (0);
}
