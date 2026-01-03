/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:53 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:46:47 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate_argument_count(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Usage: %s number_of_philosophers time_to_die time_to_eat "
			"time_to_sleep [number_of_times_each_philosopher_must_eat]\n",
			av[0]);
		return (1);
	}
	return (0);
}

static int	validate_numeric_arguments(int ac, char **av)
{
	int	i;

	(void)av;
	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
		{
			printf("Error: all arguments must be positive numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	parse_input_values(int ac, char **av, t_data *data)
{
	data->philo_count = (int)ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->meals_required = (int)ft_atol(av[5]);
	else
		data->meals_required = -1;
}

static int	validate_parsed_values(int ac, t_data *data)
{
	if (data->philo_count <= 0 || data->philo_count > 200)
	{
		printf("Error: Number of Philosophers must be between 1 and 200\n");
		return (1);
	}
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
	{
		printf("Error: All time values must be positive\n");
		return (1);
	}
	if (ac == 6 && data->meals_required <= 0)
	{
		printf("Error: Number of meals must be positive\n");
		return (1);
	}
	return (0);
}

int	parse_arguments(int ac, char **av, t_data *data)
{
	if (validate_argument_count(ac, av))
		return (1);
	if (validate_numeric_arguments(ac, av))
		return (1);
	parse_input_values(ac, av, data);
	if (validate_parsed_values(ac, data))
		return (1);
	return (0);
}
