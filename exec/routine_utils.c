/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:14:35 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/30 22:30:18 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	sleep_and_think(t_philo *philo)
{
	print(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
	print(philo, "is thinking");
}

void	eat(t_philo *philo)
{
	print(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->nb_meal_eat++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->time_to_eat);
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
	if (philo->table->dead)
	{
		release_forks(philo);
		return ;
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
	if (philo->table->must_eat_nb > 0)
		take_forks(philo);
	eat(philo);
	release_forks(philo);
	if (philo->table->must_eat_nb > 0)
	{
		if (philo->nb_meal_eat == philo->table->must_eat_nb)
			philo->belly_full = 1;
	}
}
