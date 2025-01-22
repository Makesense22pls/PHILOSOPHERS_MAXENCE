/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/01/22 19:06:28 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


int main(int argc, char **argv)
{
	t_philo *philo;
	t_table *all;
	if (parser(argc, argv) == 0)
		return (0);
	all = initialize(argc, argv);
	philo = set_table(all,argc,argv);
	if (philo == NULL)
		return (printf("Failed to create philo\n"), -1);
	monitor(philo);
	join_and_destroy_mutex(all);
	ft_free(all);
	return (0);
}


int		join_and_destroy_mutex(t_philo *all)
{
	int i = 0;
	int philos = all->number_of_philosophers;
	int j = 0;
	while( j < philos)
	{
		if (pthread_join(all->philo_threads[j], NULL)!= 0)
			return(printf("Failed to join\n"), -1);
		j++;
	}
	while (i < philos)
	{
		pthread_mutex_destroy(&all->fork[i]);
		i++;
	}
	return (0);
}
