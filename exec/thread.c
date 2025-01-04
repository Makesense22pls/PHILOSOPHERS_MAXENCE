/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2025/01/04 17:16:12 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

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
        if (data->table->someone_died) 
		{
            pthread_mutex_unlock(&data->table->death_mutex);
            exit(1);
        }
        pthread_mutex_unlock(&data->table->death_mutex);
    
        if (data->index % 2 == 0) 
        {
            pthread_mutex_lock(&data->fork[data->index]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index);
            pthread_mutex_lock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index);
        } 
        else
        {
            pthread_mutex_lock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index);
            pthread_mutex_lock(&data->fork[data->index]);
            printf("[%ld ms] Philosophe n°%d has taken a fork\n", elapsed_time(start_time), data->index);
        }
    
        pthread_mutex_lock(&data->table->death_mutex);
        long timeout = elapsed_time_meal(data);   
        if (timeout >= data->table->time_to_die) 
        {
            data->table->someone_died = 1;
            printf("[%ld ms] Philosophe n°%d est mort\n", elapsed_time(start_time), data->index);
            pthread_mutex_unlock(&data->table->death_mutex);
            pthread_mutex_unlock(&data->fork[data->index]);
            pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
            exit(1);
        }
        pthread_mutex_unlock(&data->table->death_mutex);
		
        printf("[%ld ms] Philosophe n°%d is eating, Compteur de manger = [%d]\n", elapsed_time(start_time), data->index, i);
        usleep(data->table->time_to_eat * 1e3);
        gettimeofday(&data->last_meal, NULL);
        i++;
		
        pthread_mutex_unlock(&data->fork[data->index]);
        pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);

        if (i == data->table->number_of_times_each_philosopher_must_eat)
            return (NULL);

        // Philosopher is sleeping
        printf("[%ld ms] Philosophe n°%d is sleeping\n", elapsed_time(start_time), data->index);
        usleep(data->table->time_to_sleep * 1e3);

        // Philosopher is thinking
        printf("[%ld ms] Philosophe n°%d is thinking\n", elapsed_time(start_time), data->index);
    }
    return (NULL);
}


long elapsed_time(struct timeval start_time) 
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return ((current_time.tv_sec - start_time.tv_sec) * 1000 + 
            (current_time.tv_usec - start_time.tv_usec) / 1000);
}

int elapsed_time_meal(t_philo *data) 
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return ((current_time.tv_sec - data->last_meal.tv_sec) * 1000 + 
            (current_time.tv_usec - data->last_meal.tv_usec) / 1000);
}

int check_if_only_one_philo(t_philo *all)
{
    if (all->number_of_philosophers == 1)
    {
        printf("Philosophe n°1 is thinking\n");
        usleep(all->table->time_to_die);
        printf("Philosophe n°1 is dead\n");
        return (1);
    }
    return (0);
}