/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:08:50 by maxencefour       #+#    #+#             */
/*   Updated: 2025/01/23 19:13:38 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

t_table	*initialize(int argc, char **argv)
{
	t_table	*info;
	info = malloc(sizeof(t_table));
	if (!info)
		return (NULL);
	info->is_dead = 0;
	info->num_philo = ft_atoi(argv[1]);
    info->time_to_die =  ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
	info->start_time = get_time();
	pthread_mutex_init(&info->death_lock, NULL);
	if (pthread_mutex_init(&info->meal_lock, NULL) != 0)
	{
  	 	printf("Failed to initialize meal_lock mutex\n");
    	return NULL;
	}	
	// printf("start_time oe oe  = %ld\n", info->start_time);
	info->someone_died = 0;
	info->all_ate_enough = 0;
    if (argc == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		info->number_of_times_each_philosopher_must_eat = -1;
	return (info);
}


void	innit_philo_mutex(t_table *init, int argc, char **argv)
{
	int i = 0;
	(void) argc;
	(void) argv;
	init->forks = malloc(sizeof(pthread_mutex_t) * init->num_philo);
	if (!init->forks)
		return;
	while(i < init->num_philo)
	{
		if (pthread_mutex_init(&init->forks[i], NULL) != 0)
        {
			printf("Failed to initialize mutex\n");
			return;
		}
		i++;
	}
	
}
