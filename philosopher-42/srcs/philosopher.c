/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:57:49 by eel-abed          #+#    #+#             */
/*   Updated: 2025/01/27 21:17:34 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->meals_eaten == 0)
		{
			// Prendre les fourchettes
			take_forks(philo);

			// Manger
			eat(philo);

			// Relâcher les fourchettes
			release_forks(philo);
			// Dormir et penser
			print_status(philo, "is sleeping");
			ft_usleep(philo->data->time_to_sleep);
			print_status(philo, "is thinking");
		}
		if (philo->meals_eaten < philo->data->max_meals)
		{
		
			// Prendre les fourchettes
			take_forks(philo);

			// Manger
			eat(philo);

			// Relâcher les fourchettes
			release_forks(philo);
			if(philo->meals_eaten == philo->data->max_meals)
			{
				philo->poto_plein = 1;
				printf("Alors Poto plein = %d\n", philo->poto_plein);
			}
			if (philo->meals_eaten  == philo->data->max_meals && philo->data->max_meals > 0) 
			{
				printf("Philon* %d Je break\n", philo->id);	
				break;
			}
			// Dormir et penser
			print_status(philo, "is sleeping");
			ft_usleep(philo->data->time_to_sleep);
			print_status(philo, "is thinking");
		}
		// if (philo->meals_eaten  == philo->data->max_meals && philo->data->max_meals > 0) 
		// {
		// 	printf("Philon* %d Je break\n", philo->id);	
		// 	break;
		// }
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	printf("Philo %d a mangé %d fois\n", philo->id, philo->meals_eaten);
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->time_to_eat);
}