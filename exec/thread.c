/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 21:24:08 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


void *routine(void *arg) {
    t_philo *data = (t_philo *)arg;
    struct timeval current_time;
	int i = 0;
	if (data->number_of_philosophers == 1)
	{
		usleep(data->table->time_to_die);
        printf("Philosophe n°%d est mort\n", data->index);
        return(0);
	}
	int FLAG = 0;
    while (FLAG != 1) 
	{
		int long timeout ;
        gettimeofday(&current_time, NULL);
        timeout = (current_time.tv_sec - data->last_meal.tv_sec) * 1000 + 
                (current_time.tv_usec - data->last_meal.tv_usec) / 1000;
        if (timeout > data->table->time_to_die) 
		{
            printf("Philosophe n°%d est mort\n", data->index);
            return(0);
        }
        printf("Philosophe n°%d is thinking\n",data->index);
        usleep(1000);
		
        printf("Philosophe n°%d is sleeping\n", data->index);
        usleep(data->table->time_to_sleep);
		
        pthread_mutex_lock(&data->fork[data->index]);
        pthread_mutex_lock(&data->fork[(data->index + 1) % data->number_of_philosophers]);

        gettimeofday(&data->last_meal, NULL);
        printf("Philosophe n°%d is eating, Compteur de manger = [%d]\n", data->index, i);
        usleep(data->table->time_to_eat);
		i++;
		
        pthread_mutex_unlock(&data->fork[data->index]);
        pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);
		if (i == data->table->number_of_times_each_philosopher_must_eat)
			FLAG = 1;
    }
    return (NULL);
}