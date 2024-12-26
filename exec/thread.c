/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 19:42:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


void	*routine(void *struc)
{
	t_input *data = (t_input *)struc;
	int i = 0;
	while(i < 10000000)
	{
		pthread_mutex_lock(&data->mutex);
		data->mail++;
		pthread_mutex_unlock(&data->mutex);
		i++;
	}
	return (0);
}


int		ft_thread(t_input *all)
{
	printf("GOOD\n");
	int philos = all->number_of_philosophers;
	int i = 0;
	int j = 0;
	pthread_t philo_threads [all->number_of_philosophers];
	pthread_mutex_init(&all->mutex,NULL);
	while( i < philos)
	{
		if (pthread_create(&philo_threads[i], NULL, routine, all) != 0)
			return(printf("Failed to create thread\n"), -1);
		i++;
		printf("pthread [%d] has started exec\n",i );
	}
	while( j < philos)
	{
		if (pthread_join(philo_threads[j], NULL)!= 0)
			return(printf("Failed to join\n"), -1);
		printf("pthread [%d] has finished exec\n",j );
		j++;
	}
	pthread_mutex_destroy(&all->mutex);
	printf("Number of Mails %d\n", all->mail);
	return (0);
}


void dinner_start(t_input *all)
{
	if (all->table->number_of_times_each_philosopher_must_eat == 0)
		return;
	else if (all->number_of_philosophers == 1)
		;//faire
	else
		{
			printf("TAMERE\n" );
			ft_thread(all);
		}
		
}
