/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:51:43 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/22 17:58:20 by mafourni         ###   ########.fr       */
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