/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 18:19:42 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


void *routine(void *arg) {
    t_philo *data = (t_philo *)arg;
    struct timeval current_time;

    while (1) {
		int long timeout ;
        printf("Philosophe n°%d pense\n", data->index);
        usleep(1000);

        gettimeofday(&current_time, NULL);
        timeout = (current_time.tv_sec - data->last_meal.tv_sec) * 1000 + 
                            (current_time.tv_usec - data->last_meal.tv_usec) / 1000;
        if (timeout > data->table->time_to_die) 
		{
            printf("Philosophe n°%d est mort\n", data->index);
            return(0);
        }

        pthread_mutex_lock(&data->fork[data->index]);
        pthread_mutex_lock(&data->fork[(data->index + 1) % data->number_of_philosophers]);

        printf("Philosophe n°%d mange\n", data->index);
        gettimeofday(&data->last_meal, NULL);
        usleep(data->table->time_to_eat);

        pthread_mutex_unlock(&data->fork[data->index]);
        pthread_mutex_unlock(&data->fork[(data->index + 1) % data->number_of_philosophers]);

        printf("Philosophe n°%d dort\n", data->index);
        usleep(data->table->time_to_sleep);
    }
    return (NULL);
}

int		thread_join(t_philo *all)
{
	int i = 0;
	printf("GOOD\n");
	int philos = all->number_of_philosophers;
	int j = 0;
	while( j < philos)
	{
		if (pthread_join(all->philo_threads[j], NULL)!= 0)
			return(printf("Failed to join\n"), -1);
		printf("pthread [%d] has finished exec\n",j );
		j++;
	}
	while (i < philos)
	{
		pthread_mutex_destroy(&all->fork[i]);
		i++;
	}
	printf("Number of Mails %d\n", all->mail);
	return (0);
}



void dinner_start(t_philo *all)
{
	if (all->table->number_of_times_each_philosopher_must_eat == 0)
		return;
	else if (all->number_of_philosophers == 1)
		;//faire
	else
		{
			printf("TAMERE\n" );
			thread_join(all);
		}
}
