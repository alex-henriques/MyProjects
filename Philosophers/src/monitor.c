/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:47 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:46:58 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_death(t_data *data)
{
	int		i;
	long	current_time;
	long	last_meal;

	i = 0;
	while (i < data->philo_count)
	{
		current_time = get_time();
		pthread_mutex_lock(&data->meal_mutex);
		last_meal = data->philos[i].last_meal_time;
		pthread_mutex_unlock(&data->meal_mutex);
		if (current_time - last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->death_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->death_mutex);
			pthread_mutex_lock(&data->print_mutex);
			printf("%ld %d died\n", current_time - data->start_time,
				data->philos[i].id);
			pthread_mutex_unlock(&data->print_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_all_ate_enough(t_data *data)
{
	int	i;
	int	finished_eating;
	int	meals_eaten;

	if (data->meals_required == -1)
		return (0);
	finished_eating = 0;
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->meal_mutex);
		meals_eaten = data->philos[i].meals_eaten;
		pthread_mutex_unlock(&data->meal_mutex);
		if (meals_eaten >= data->meals_required)
			finished_eating++;
		i++;
	}
	if (finished_eating == data->philo_count)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->all_ate_enough = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_philo_death(data) || check_all_ate_enough(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}

int	check_death(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_mutex);
	result = data->someone_died;
	pthread_mutex_unlock(&data->death_mutex);
	return (result);
}

int	check_meals_complete(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_mutex);
	result = data->all_ate_enough;
	pthread_mutex_unlock(&data->death_mutex);
	return (result);
}
