/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:48:57 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/04 05:19:45 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_norminette(philo);
	while (!getter(&philo->table->dead_lock, &philo->table->dead))
	{
		if (philo->table->max <= 0)
		{
			take_forks(philo);
			take_eat_release(philo);
			if (getter(&philo->table->dead_lock, &philo->table->dead))
				break ;
			sleep_and_think(philo);
		}
		else if (philo->nb_meal_eat < philo->table->max)
		{
			take_eat_release(philo);
			if (philo->nb_meal_eat == philo->table->max)
				return (NULL);
			if (getter(&philo->table->dead_lock, &philo->table->dead))
				break ;
			sleep_and_think(philo);
		}
	}
	return (NULL);
}

void	wait_norminette(t_philo *philo)
{
	while (!getter(&philo->table->dead_lock, &philo->table->all_ready))
		usleep(10);
	if (philo->index % 2 == 0)
		usleep(100);
}

void	*philo_1_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_usleep(philo->table->time_to_die);
	return (NULL);
}

int	getter(pthread_mutex_t *mtx, int *i)
{
	int	tmp;

	pthread_mutex_lock(mtx);
	tmp = *i;
	pthread_mutex_unlock(mtx);
	return (tmp);
}

void	setter(pthread_mutex_t *mtx, int *i, int new)
{
	pthread_mutex_lock(mtx);
	*i = new;
	pthread_mutex_unlock(mtx);
}
