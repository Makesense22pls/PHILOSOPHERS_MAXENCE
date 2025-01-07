/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2025/01/07 18:49:35 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	set_table(t_philo *init, int argc, char **argv)
{
	(void) argc;
	init->number_of_philosophers = ft_atoi(argv[1]);
	init->philo_threads = malloc(sizeof(pthread_t) * init->number_of_philosophers);
	if (!init->philo_threads)
		return;
	innit_philo_mutex(init,argc, argv);
	gettimeofday(&init->last_meal, NULL);
	while(init->num_philo < init->number_of_philosophers)
		{
			t_philo *philo = malloc(sizeof(t_philo));
        	*philo = *init;
       		philo->index = init->num_philo;
			if(pthread_create(&init->philo_threads[init->num_philo], NULL, (void *)routine, (void *)philo) != 0)
			{
				printf("Failed to create a philo\n");
				return;
			}
			init->num_philo++;
		}
}

void *routine(void *arg) 
{
    t_philo *data = (t_philo *)arg;
    struct timeval start_time;
    gettimeofday(&start_time, NULL);
    int i = 0;
    
    if (check_if_only_one_philo(data) == 1)
        return (NULL);
    gettimeofday(&data->last_meal, NULL);
    while (1)
    {
        pthread_mutex_lock(&data->table->death_mutex);
        // if (data->table->someone_died) 
		// {
        //     pthread_mutex_unlock(&data->table->death_mutex);
        //     exit(1);
        // }
        pthread_mutex_unlock(&data->table->death_mutex);
    
        if (data->index % 2 == 0) 
        {
            pthread_mutex_lock(&data->fork[data->index]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index + 1);
            pthread_mutex_lock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index + 1);
        } 
        else
        {
            pthread_mutex_lock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index + 1);
            pthread_mutex_lock(&data->fork[data->index]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index + 1);
        }
    
        pthread_mutex_lock(&data->table->death_mutex);
        long timeout = elapsed_time_meal(data);   
        if (timeout >= data->table->time_to_die) 
        {
            data->table->someone_died = 1;
            printf("[%ld ms] Philosophe n°%d est mort\n", elapsed_time(start_time), data->index + 1);
            pthread_mutex_unlock(&data->table->death_mutex);
            pthread_mutex_unlock(&data->fork[data->index]);
            pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
            exit(1);
        }
        pthread_mutex_unlock(&data->table->death_mutex);
		
        printf("[%ld ms] Philosophe n°%d is eating, Compteur de manger = [%d]\n", elapsed_time(start_time), data->index + 1, i);
        usleep(data->table->time_to_eat * 1e3);
        gettimeofday(&data->last_meal, NULL);
        i++;
		
        pthread_mutex_unlock(&data->fork[data->index]);
        pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);

        if (i == data->table->number_of_times_each_philosopher_must_eat)
            return (NULL);

        printf("[%ld ms] Philosophe n°%d is sleeping\n", elapsed_time(start_time), data->index + 1);
        usleep(data->table->time_to_sleep * 1e3);

        printf("[%ld ms] Philosophe n°%d is thinking\n", elapsed_time(start_time), data->index + 1);
    }
    return (NULL);
}
