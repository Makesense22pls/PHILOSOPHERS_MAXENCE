/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:14 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/28 23:20:51 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*monitor(void *arg)
{
	t_philo	*philos;
	int		i;
	int		bellies_full;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		bellies_full = 1;
		while (i < philos->table->num_philo)
		{
			pthread_mutex_lock(&philos->table->meal_lock);
			if (philos->belly_full == 0 && get_time() - philos[i].last_meal > philos->table->time_to_die)
			{
				print(&philos[i], "died");
				exit(1);
			}
			if (philos->table->must_eat_nb > 0 && philos[i].nb_meal_eat < philos->table->must_eat_nb)
				bellies_full = 0;
			pthread_mutex_unlock(&philos->table->meal_lock);
			i++;
		}
		if (bellies_full && philos->table->must_eat_nb > 0)
				exit(0);
		usleep(1000);
	}
	return (NULL);
}