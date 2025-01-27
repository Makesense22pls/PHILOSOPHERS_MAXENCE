/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:58:10 by eel-abed          #+#    #+#             */
/*   Updated: 2025/01/27 20:27:47 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor(void *arg)
{
	t_philo	*philos;
	int		i;
	int		all_full;

	philos = (t_philo *)arg;
	while (1)
	{
		i = -1;
		all_full = 1;
		while (++i < philos->data->num_philos)
		{
			pthread_mutex_lock(&philos->data->meal_lock);
			if (philos->poto_plein == 0 && get_time() - philos[i].last_meal > philos->data->time_to_die)
			{
				print_status(&philos[i], "died");
				exit(0); // À adapter avec une variable de contrôle
			}
			if (philos->data->max_meals > 0 && 
				philos[i].meals_eaten < philos->data->max_meals)
				all_full = 0;
			pthread_mutex_unlock(&philos->data->meal_lock);
		}
		if (all_full && philos->data->max_meals > 0)
			exit(0); // À adapter
		usleep(1000);
	}
	return (NULL);
}
