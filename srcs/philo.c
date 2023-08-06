/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:35:14 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/08/06 16:11:35 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_params(int argc, char **argv)
{
	t_params *params;
	
	//parameters for arguments
	params->philo_nbr = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argvp[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params->max_meals = ft_atoi(arg[5]);
	//extra
	params->is_dead = 0;
	//params->timer = 0;
	//threaths and mutex	
}

int main(int argc, char **argv)
{
	int i = 0;
	if(argc < 5 | argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	else
	{
		while(argv[1][i])
		{
			i++;
		}
		print_results();
	}
	return(0);
}