/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:30:09 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/08/03 15:03:59 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//returns the current time in miliseconds. 
long long time_displayer(void)
{
    struct timeval currentTime;
	long long milliseconds;

    gettimeofday(&currentTime, NULL);
    milliseconds = currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000;

    return (milliseconds);
}

void	print_results()
{
	printf("now we talk\n");
	printf("%lld", time_displayer());	
}