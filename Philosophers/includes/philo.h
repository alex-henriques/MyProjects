/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:28:57 by alehenri          #+#    #+#             */
/*   Updated: 2025/08/11 11:47:31 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

# define PHILO_MAX 200

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_required;
	long			start_time;
	int				someone_died;
	int				all_ate_enough;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	t_philo			*philos;
}	t_data;

//actions.c
void	print_action(t_philo *philo, char *action);
//cleanup.c
void	cleanup(t_data *data);
//init.c
int		init_mutexes(t_data *data);
void	init_philo(t_data *data);
int		init_data(t_data *data);
//monitor.c
int		check_philo_death(t_data *data);
int		check_all_ate_enough(t_data *data);
void	*monitor_routine(void *arg);
int		check_death(t_data *data);
int		check_meals_complete(t_data *data);
//parse.c
int		parse_arguments(int ac, char **av, t_data *data);
//routine.c
int		should_stop(t_data *data);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_and_think(t_philo *philo);
void	*philo_routine(void *arg);
//time_utils.c
long	get_time(void);
void	ft_usleep(long time);
//utils.c
long	ft_atol(const char *str);
int		is_valid_number(char *str);
//main.c
int		create_threads(t_data *data, pthread_t *monitor);
int		main(int ac, char **av);

#endif