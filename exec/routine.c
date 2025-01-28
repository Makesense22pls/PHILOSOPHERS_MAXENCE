/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:48:57 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/28 23:20:40 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->table->must_eat_nb <= 0)
			routine_without_max(philo);
		else
			if (philo->nb_meal_eat < philo->table->must_eat_nb)
			{
				take_forks(philo);
				eat(philo);
				release_forks(philo);
				if (philo->nb_meal_eat == philo->table->must_eat_nb)
					philo->belly_full = 1;
				if (philo->nb_meal_eat  == philo->table->must_eat_nb) 
					break;
				print(philo, "is sleeping");
				ft_usleep(philo->table->time_to_sleep);
				print(philo, "is thinking");
			}
	}
	return (NULL);
}

void	routine_without_max(t_philo *philo)
{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		print(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);
		print(philo, "is thinking");
}

void	eat(t_philo *philo)
{
	print(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->nb_meal_eat ++;
	printf("Philo %d a mangé %d fois\n", philo->index, philo->nb_meal_eat);
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

void	print(t_philo *philo, char *txt)
{
	long	timestamp;

	timestamp = get_time() - philo->table->start_time;
	printf("[%ld ms] Philo n°%d %s\n", timestamp, philo->index, txt);
}

// void	*routine(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	while (1)
// 	{
// 		if (philo->nb_meal_eat == 0)
// 		{
// 			// Prendre les fourchettes
// 			take_forks(philo);

// 			// Manger
// 			eat(philo);

// 			// Relâcher les fourchettes
// 			release_forks(philo);
// 			// Dormir et penser
// 			print(philo, "is sleeping");
// 			ft_usleep(philo->table->time_to_sleep);
// 			print(philo, "is thinking");
// 		}
// 		if (philo->nb_meal_eat < philo->table->must_eat_nb)
// 		{
		
// 			// Prendre les fourchettes
// 			take_forks(philo);

// 			// Manger
// 			eat(philo);

// 			// Relâcher les fourchettes
// 			release_forks(philo);
			// if(philo->nb_meal_eat == philo->table->must_eat_nb)
			// {
			// 	philo->belly_full = 1;
			// 	printf("Alors Poto plein = %d\n", philo->belly_full);
			// }
			// if (philo->nb_meal_eat  == philo->table->must_eat_nb && philo->table->must_eat_nb > 0) 
			// {
			// 	printf("Philon* %d Je break\n", philo->index + 1);	
			// 	break;
			// }
// 			// Dormir et penser
// 			print(philo, "is sleeping");
// 			ft_usleep(philo->table->time_to_sleep);
// 			print(philo, "is thinking");
// 		}
// 		// if (philo->nb_meal_eat  == philo->table->must_eat_nb && philo->table->must_eat_nb > 0) 
// 		// {
// 		// 	printf("Philon* %d Je break\n", philo->index);	
// 		// 	break;
// 		// }
// 	}
// 	return (NULL);
// }
// void	*routine(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	while (1)
// 	{
// 		if (philo->nb_meal_eat == 0)
// 		{
// 			// Prendre les fourchettes
// 			take_forks(philo);

// 			// Manger
// 			eat(philo);

// 			// Relâcher les fourchettes
// 			release_forks(philo);
// 			// Dormir et penser
// 			print(philo, "is sleeping");
// 			ft_usleep(philo->table->time_to_sleep);
// 			print(philo, "is thinking");
// 		}
// 		if (philo->nb_meal_eat < philo->table->must_eat_nb)
// 		{
		
// 			// Prendre les fourchettes
// 			take_forks(philo);

// 			// Manger
// 			eat(philo);

// 			// Relâcher les fourchettes
// 			release_forks(philo);
// 			if(philo->nb_meal_eat == philo->table->must_eat_nb)
// 			{
// 				philo->belly_full = 1;
// 				printf("Alors Poto plein = %d\n", philo->belly_full);
// 			}
// 			if (philo->nb_meal_eat  == philo->table->must_eat_nb && philo->table->must_eat_nb > 0) 
// 			{
// 				printf("Philon* %d Je break\n", philo->index);	
// 				break;
// 			}
// 			// Dormir et penser
// 			print(philo, "is sleeping");
// 			ft_usleep(philo->table->time_to_sleep);
// 			print(philo, "is thinking");
// 		}
// 		if (philo->nb_meal_eat  == philo->table->must_eat_nb && philo->table->must_eat_nb > 0) 
// 		{
// 			printf("Philon* %d Je break\n", philo->index);	
// 			break;
// 		}
// 	}
// 	return (NULL);
// }