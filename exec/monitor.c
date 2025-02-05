/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:14 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/05 16:49:39 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	int		bellies_full;

	philo = (t_philo *)arg;
	while (!(getter(&philo->table->dead_lock, &philo->table->dead)))
	{
		i = -1;
		bellies_full = 1;
		while (++i < philo->table->num_philo
			&& !(getter(&philo->table->dead_lock, &philo->table->dead)))
		{
			pthread_mutex_lock(&philo->table->meal_lock);
			if (philo->belly_full == 0 && get_time()
				- philo[i].last_meal >= philo->table->time_to_die)
				return (dead_guy(philo, i), NULL);
			if (philo->table->max > 0 && philo->nb_meal_eat < philo->table->max)
				bellies_full = 0;
			pthread_mutex_unlock(&philo->table->meal_lock);
		}
		if (bellies_full && philo->table->max > 0)
			return (0);
		usleep(50);
	}
	return (NULL);
}

void	dead_guy(t_philo *philos, int i)
{
	print(&philos[i], "died");
	pthread_mutex_unlock(&philos->table->meal_lock);
	pthread_mutex_lock(&philos->table->dead_lock);
	philos->table->dead = 1;
	pthread_mutex_unlock(&philos->table->dead_lock);
}
