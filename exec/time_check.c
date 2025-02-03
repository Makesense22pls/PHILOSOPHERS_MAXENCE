/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:51:43 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/04 00:14:31 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long elapsed_time(t_philo *philo) 
{
    long	time;

	time = get_time() - philo->table->start_time;
	return (time);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long milliseconds)
{
	long	start;

	start = get_time();
	while (get_time() - start < milliseconds)
		usleep(100);
}
void	smart_sleep(long milliseconds, t_philo *philo)
{
	long	start;

	start = get_time();
	while (get_time() - start < milliseconds)
	{
		if(!philo->table->dead)
			usleep(100);
		else
			break;
	}
}