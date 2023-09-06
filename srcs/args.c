/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:38:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/06 12:42:06 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_check(char **argv, int argc)
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (0);
	return (1);
}

void	args_error(void)
{
	ft_putstr("\x1b[31mInvalid arguments!\x1b[0m\n");
	ft_putstr("\x1b[35mYour aguments should contain:\x1b[0m\n");
	ft_putstr("\x1b[35mNumber of philos, die ⏰, eat ⏰ & sleep ⏰\x1b[0m\n");
	ft_putstr("\x1b[35mOptional: times_each_philosopher_must_eat\x1b[0m\n");
	ft_putstr("\x1b[32mexample: ./philo.. 5 100 200 200 3\x1b[0m\n");
}
