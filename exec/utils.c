/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:45:31 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/29 22:58:56 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

// int	philosopher_dead(t_philo *philo, int time_to_die)
// {
// 	pthread_mutex_lock(&philo->table->meal_lock);
// 	if (get_time() - philo->last_meal >= time_to_die)
// 		return (pthread_mutex_unlock(&philo->table->meal_lock), 1);
// 	pthread_mutex_unlock(&philo->table->meal_lock);
// 	return (0);
// }

// // Check if any philo died

// int	check_if_dead(t_philo *philos)
// {
//     int	i;

// 	i = 0;
// 	while (i < philos->number_of_philosophers)
// 	{
// 		if (philosopher_dead(&philos[i], philos->table->time_to_die))
// 		{
// 			print(&philos[i], "died");
// 			pthread_mutex_lock(&philos->table->dead_lock);
// 			philos->table->dead = 1;
// 			pthread_mutex_unlock(&philos->table->dead_lock);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// // Checks if all the philos ate the num_of_meals


// // Monitor thread routine

// void	*monitor(void *pointer)
// {
// 	t_philo	*philos;

// 	philos = (t_philo *)pointer;
// 	while (1)
// 	{
// 		if (check_if_dead(philos) == 1)
// 			break ;
// 	}
// 	return (pointer);
// }