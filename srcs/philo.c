/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:35:14 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/05 13:18:41 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(t_table *table, int philo_num, int must_eat_num)
{
	table->num_philos = philo_num;
	table->must_eat_num = must_eat_num;
	table->has_dead = 0;
	gettimeofday(&table->start_time, NULL);
	table->philos = malloc(philo_num * sizeof(t_philo));
	table->chopsticks = malloc(philo_num * sizeof(pthread_mutex_t));
	table->threads = malloc(philo_num * sizeof(pthread_t));
	pthread_mutex_init(&table->print_lock, NULL);
	memset(table->philos, 0, philo_num * sizeof(t_philo));
}

void	init_philos(t_table *table, int time_to_die, int time_to_eat, 
		int time_to_sleep)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].time_to_die = time_to_die;
		table->philos[i].time_to_eat = time_to_eat;
		table->philos[i].time_to_sleep = time_to_sleep;
		table->philos[i].last_time_to_eat = 0;
		table->philos[i].eat_count = 0;
		table->philos[i].table = table;
		table->philos[i].left_chopstick = &table->chopsticks[i];
		table->philos[i].right_chopstick = &table->chopsticks[(i + 1)
			% table->num_philos];
		i++;
	}
}

void	init_chopsticks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
		pthread_mutex_init(&table->chopsticks[i], NULL);
}

void	philo_sleep(int type, t_philo *philo)
{
	if (type == 1)
	{
		print_log(philo, "\x1b[44mis sleeping\x1b[0m\n");
		if (philo->time_to_sleep >= philo->time_to_die)
			usleep(1000 * (philo->time_to_die));
		else
			usleep(philo->time_to_sleep * 1000);
	}
	else
	{
		if (philo->time_to_eat >= philo->time_to_die)
			usleep(1000 * (philo->time_to_die));
		else
			usleep(philo->time_to_eat * 1000);
	}
}
