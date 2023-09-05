/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:35:14 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/05 13:19:04 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	long	current_time;

	current_time = get_timestamp(philo);
	if (current_time - philo->last_time_to_eat >= philo->time_to_die)
	{
		print_log(philo, "\x1b[41mdied\x1b[0m\n");
		pthread_mutex_lock(&philo->table->print_lock);
		philo->table->has_dead = 1;
		pthread_mutex_unlock(&philo->table->print_lock);
		return (1);
	}
	pthread_mutex_lock(&philo->table->print_lock);
	if (philo->table->has_dead)
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
	return (0);
}

long	get_timestamp(t_philo *philo)
{
	struct timeval	current_time;
	long			start_time;
	long long		milliseconds;

	gettimeofday(&current_time, NULL);
	start_time = philo->table->start_time.tv_sec * 1000
		+ philo->table->start_time.tv_usec / 1000;
	milliseconds = current_time.tv_sec * 1000
		+ current_time.tv_usec / 1000;
	return (milliseconds - start_time);
}

void	print_log(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (!philo->table->has_dead)
		printf("%ld %d %s\n", get_timestamp(philo), philo->id, s);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	eat_2(t_philo *philo, pthread_mutex_t *first_chopstick,
		pthread_mutex_t *second_chopstick)
{
	pthread_mutex_lock(first_chopstick);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(first_chopstick);
		return ;
	}
	print_log(philo, "\x1b[45mhas taken a chopstick\x1b[0m");
	if (first_chopstick != second_chopstick)
	{
		pthread_mutex_lock(second_chopstick);
		print_log(philo, "\x1b[45mhas taken a chopstick\x1b[0m");
		print_log(philo, "\x1b[43mis eating\x1b[0m");
		philo->eat_count++;
		philo->last_time_to_eat = get_timestamp(philo);
		philo_sleep(2, philo);
		pthread_mutex_unlock(second_chopstick);
	}
	else
		usleep(philo->time_to_die * 1000);
	pthread_mutex_unlock(first_chopstick);
}

void	eat(t_philo *philo, int type)
{
	pthread_mutex_t	*first_chopstick;
	pthread_mutex_t	*second_chopstick;

	if (type == 1)
	{
		first_chopstick = philo->left_chopstick;
		second_chopstick = philo->right_chopstick;
	}
	else
	{
		first_chopstick = philo->right_chopstick;
		second_chopstick = philo->left_chopstick;
	}
	eat_2(philo, first_chopstick, second_chopstick);
}
