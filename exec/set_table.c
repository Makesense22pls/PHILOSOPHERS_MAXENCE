/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2025/01/28 23:20:59 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

t_philo	*set_table(t_table *info)
{
    int i;
	t_philo	*philo;
	philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!philo)
    	return(NULL);
	i = -1 ;
	while(++i < info->num_philo)
	{
		philo[i].table = info;
        philo[i].belly_full = 0;
		philo[i].nb_meal_eat = 0;
    	philo[i].index = i + 1;
		philo[i].last_meal = info->start_time;
		if (pthread_create(&philo[i].ph_thread, NULL, routine, &philo[i]) != 0)
		{
			printf("Failed to create a philo\n");
			return(NULL);
		}
	}
	return (philo);
}
