/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:48:57 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/04 00:15:47 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->dead)
	{
		if (philo->table->must_eat_nb <= 0)
		{
			take_forks(philo);
			if (philo->table->dead)
				return (release_forks(philo), NULL);
			take_eat_release(philo);
			if (philo->table->dead)
				break ;
			sleep_and_think(philo);
		}
		else if (philo->nb_meal_eat < philo->table->must_eat_nb)
		{
			take_eat_release(philo);
			if (philo->nb_meal_eat == philo->table->must_eat_nb)
				return (NULL);
			sleep_and_think(philo);
		}
	}
	return (NULL);
}
void	*philo_1_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_usleep(philo->table->time_to_die);
	return (NULL);
}