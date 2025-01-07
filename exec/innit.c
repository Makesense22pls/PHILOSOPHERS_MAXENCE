/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:08:50 by maxencefour       #+#    #+#             */
/*   Updated: 2025/01/07 17:56:56 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

t_philo	*initialize(int argc, char **argv)
{
	t_philo	*init;
	init = malloc(sizeof(t_philo));
	if (!init)
		return (NULL);
	init->table = malloc(sizeof(t_table));
	if (!init->table)
		return (NULL);
	init->num_philo = 0;
	init->argc  = argc;
    init->table->time_to_die =  ft_atoi(argv[2]);
    init->table->time_to_eat = ft_atoi(argv[3]);
    init->table->time_to_sleep = ft_atoi(argv[4]);
	init->table->someone_died = 0;
	init->table->all_ate_enough = 0;
	pthread_mutex_init(&init->table->death_mutex, NULL);
    if (argc == 6)
		init->table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		init->table->number_of_times_each_philosopher_must_eat = -1;
	return (init);
}


void	innit_philo_mutex(t_philo *init, int argc, char **argv)
{
	int i = 0;
	(void) argc;
	(void) argv;
	init->fork = malloc(sizeof(pthread_mutex_t) * init->number_of_philosophers);
	if (!init->fork)
		return;
	while(i < init->number_of_philosophers)
		{
			if (pthread_mutex_init(&init->fork[i], NULL) != 0)
            {
				printf("Failed to initialize mutex\n");
				return;
			}
			i++;
		}
	
}