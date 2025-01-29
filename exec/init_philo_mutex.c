/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:08:50 by maxencefour       #+#    #+#             */
/*   Updated: 2025/01/29 21:43:46 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

t_table	*initialize(int argc, char **argv)
{
	t_table	*info;
	info = malloc(sizeof(t_table));
	if (!info)
		return (NULL);
	info->dead = 0;
	info->num_philo = ft_atoi(argv[1]);
    info->time_to_die =  ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
		info->must_eat_nb = ft_atoi(argv[5]);
	else
		info->must_eat_nb = -1;
	info->start_time = get_time();
	return (info);
}


int		innit_philo_mutex(t_table *table)
{
	int i ;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->forks)
		return (1);
	i = 0;
	while(i < table->num_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
        {
			printf("Failed to initialize fork mutex\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&table->meal_lock, NULL) != 0)
	{
  	 	printf("Failed to initialize meal_lock mutex\n");
    	return(1);
	}
	if (pthread_mutex_init(&table->dead_lock, NULL) != 0)
	{
    	printf("Failed to initialize dead_lock mutex\n");
    	return(1);
	}
	return(0);
}