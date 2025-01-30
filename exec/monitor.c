/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:14 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/30 22:34:45 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*monitor(void *arg)
{
	t_philo	*philos;
	int		i;
	int		bellies_full;

	philos = (t_philo *)arg;
	while (!philos->table->dead)
	{
		i = -1;
		bellies_full = 1;
		while (++i < philos->table->num_philo && !philos->table->dead)
		{
			pthread_mutex_lock(&philos->table->meal_lock);
			if (philos->belly_full == 0 && get_time()
				- philos[i].last_meal > philos->table->time_to_die)
				return (dead_guy(philos, i), NULL);
			if (philos->table->must_eat_nb > 0
				&& philos->nb_meal_eat < philos->table->must_eat_nb)
				bellies_full = 0;
			pthread_mutex_unlock(&philos->table->meal_lock);
		}
		if (bellies_full && philos->table->must_eat_nb > 0)
			return (0);
		usleep(50);
	}
	return (NULL);
}

void	dead_guy(t_philo *philos, int i)
{
	pthread_mutex_lock(&philos->table->dead_lock);
	philos->table->dead = 1;
	pthread_mutex_unlock(&philos->table->dead_lock);
	print(&philos[i], "died");
	pthread_mutex_unlock(&philos->table->meal_lock);
}