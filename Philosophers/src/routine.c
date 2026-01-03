/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:59 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:46:27 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_stop(t_data *data)
{
	int	death_flag;
	int	meals_flag;

	pthread_mutex_lock(&data->death_mutex);
	death_flag = data->someone_died;
	meals_flag = data->all_ate_enough;
	pthread_mutex_unlock(&data->death_mutex);
	return (death_flag || meals_flag);
}

/*
0  1  2  3  4
01 21 23 43 04

0  1  2  3
01 21 23 03
*/

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0 || philo->id == philo->data->philo_count - 1)
	{
		pthread_mutex_lock(philo->right_fork);
		if (!should_stop(philo->data))
			print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (!should_stop(philo->data))
			print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (!should_stop(philo->data))
			print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		if (!should_stop(philo->data))
			print_action(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_and_think(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_action(philo, "is thinking");
	if (philo->data->philo_count % 2 == 1)
		ft_usleep(1);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
	{
		print_action(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	while (!should_stop(philo->data))
	{
		eat(philo);
		if (should_stop(philo->data))
			break ;
		sleep_and_think(philo);
	}
	return (NULL);
}
