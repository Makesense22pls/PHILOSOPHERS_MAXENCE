/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2025/01/04 13:17:20 by maxencefour      ###   ########.fr       */
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
	int FLAG = 0;
    while (FLAG != 1) 
	{
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

        printf("[%ld ms] Philosophe n°%d is eating, Compteur de manger = [%d]\n", elapsed_time(start_time), data->index, i);
        gettimeofday(&data->last_meal, NULL);
        usleep(data->table->time_to_eat * 1e3);
        i++;

        pthread_mutex_unlock(&data->fork[data->index]);
        pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);

        printf("[%ld ms] Philosophe n°%d is sleeping\n", elapsed_time(start_time), data->index);
        usleep(data->table->time_to_sleep * 1e3);
        printf("[%ld ms] Philosophe n°%d is thinking\n", elapsed_time(start_time), data->index);

        long timeout = elapsed_time_meal(data);
        if (timeout > data->table->time_to_die) 
        {
            printf("[%ld ms] Philosophe n°%d est mort\n", elapsed_time(start_time), data->index);
            exit(0);
        }
        if (i == data->table->number_of_times_each_philosopher_must_eat)
            FLAG = 1;
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