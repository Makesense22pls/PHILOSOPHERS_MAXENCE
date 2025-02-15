/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:14:35 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/05 17:21:29 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	sleep_and_think(t_philo *philo)
{
	int	i;

	print(philo, "is sleeping");
	smart_sleep(philo->table->time_to_sleep, philo);
	print(philo, "is thinking");
	if (philo->table->num_philo % 2 != 0)
	{
		i = (((philo->table->time_to_eat) * 2 - (philo->table->time_to_sleep))
				* 0.5);
		smart_sleep(i, philo);
	}
}

void	eat(t_philo *philo)
{
	print(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->nb_meal_eat++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	smart_sleep(philo->table->time_to_eat, philo);
}

void	take_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->index - 1;
	right_fork = philo->index % philo->table->num_philo;
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		pthread_mutex_lock(&philo->table->forks[left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		pthread_mutex_lock(&philo->table->forks[right_fork]);
	}
	print(philo, "has taken a fork");
	print(philo, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->index - 1;
	right_fork = philo->index % philo->table->num_philo;
	pthread_mutex_unlock(&philo->table->forks[left_fork]);
	pthread_mutex_unlock(&philo->table->forks[right_fork]);
}

void	take_eat_release(t_philo *philo)
{
	if (philo->table->max > 0)
		take_forks(philo);
	eat(philo);
	release_forks(philo);
	if (philo->table->max > 0)
	{
		if (philo->nb_meal_eat == philo->table->max)
			philo->belly_full = 1;
	}
}
