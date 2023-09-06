/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:35:14 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/06 13:23:16 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	while (!is_dead(philo)
		&& !((philo->eat_count == philo->table->must_eat_num)
			&& philo->table->must_eat_num != 0))
	{
		print_log(philo, "\x1b[42mis thinking\x1b[0m");
		if (philo->id % 2 == 1)
			eat(philo, 1);
		else
			eat(philo, 2);
		if (!is_dead(philo)
			&& !((philo->eat_count == philo->table->must_eat_num)
				&& philo->table->must_eat_num != 0))
			philo_sleep(1, philo);
	}
	return (NULL);
}

void	free_all(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
		pthread_mutex_destroy(&table->chopsticks[i]);
	pthread_mutex_destroy(&table->print_lock);
	if (table->philos != NULL)
		free(table->philos);
	if (table->chopsticks != NULL)
		free(table->chopsticks);
	if (table->threads != NULL)
		free(table->threads);
}

int	initialize_table_and_philos(t_table *table, char **argv, int argc)
{
	int		must_eat_num;

	must_eat_num = -1;
	if (!arg_check(argv, argc) || ft_atoi(argv[1]) == -1
		|| ft_atoi(argv[2]) == -1 || ft_atoi(argv[3]) == -1
		|| ft_atoi(argv[4]) == -1 || (argc == 6 && ft_atoi(argv[5]) == -1)
		|| !is_numeric_string(argv[1]) || !is_numeric_string(argv[2])
		|| !is_numeric_string(argv[3]) || !is_numeric_string(argv[4])
		|| (argc == 6 && !is_numeric_string(argv[5])))
	{
		args_error();
		return (1);
	}
	if (argc == 6)
		must_eat_num = ft_atoi(argv[5]);
	init_table(table, ft_atoi(argv[1]), must_eat_num);
	init_chopsticks(table);
	init_philos(table, ft_atoi(argv[2]), ft_atoi(argv[3]),
		ft_atoi(argv[4]));
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	if (initialize_table_and_philos(&table, argv, argc) != 0)
		return (1);
	i = -1;
	while (++i < table.num_philos)
		pthread_create(&table.threads[i], NULL,
			start_routine, &table.philos[i]);
	i = -1;
	while (++i < table.num_philos)
		pthread_join(table.threads[i], NULL);
	free_all(&table);
	return (0);
}
