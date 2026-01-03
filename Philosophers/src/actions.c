/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:15 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:36:26 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	long	timestamp;
	int		print;

	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	print = (!philo->data->someone_died && !philo->data->all_ate_enough);
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (print)
	{
		timestamp = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}
