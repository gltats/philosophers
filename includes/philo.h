/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:14:37 by ikayacio          #+#    #+#             */
/*   Updated: 2023/09/01 18:08:15 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_philo {
	int				id;
	long			last_time_to_eat;
	int				eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_table			*table;
	pthread_mutex_t	*left_chopstick;
	pthread_mutex_t	*right_chopstick;
}	t_philo;

typedef struct s_table {
	int				num_philos;
	t_philo			*philos;
	int				must_eat_num;
	int				has_dead;
	pthread_mutex_t	*chopsticks;
	pthread_mutex_t	print_lock;
	pthread_t		*threads;
	struct timeval	start_time;
}	t_table;

void	init_table(t_table *table, int philo_num, int must_eat_num);
void	init_philos(t_table *table, int time_to_die, int time_to_eat, int time_to_sleep);
void	init_chopsticks(t_table *table);
long	get_timestamp(t_philo *philo);
void	print_log(t_philo *philo, char *s);
void	eat(t_philo *philo, int type);
int		is_dead(t_philo *philo);
void	philo_sleep(int type, t_philo *philo);
#endif
