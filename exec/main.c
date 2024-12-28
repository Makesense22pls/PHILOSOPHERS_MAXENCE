/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 21:28:54 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int main(int argc, char **argv)
{
	t_philo *all;
	int i;
	(void) i;
	if (argc != 6 && argc != 5)
		return (printf("Wrong numbers of args\n"), 0);
	if (ft_isdigit_philo(argv,argc) == 0)
		return(printf("Only positive numbers accepted"), 0);
	all = initialize(argc, argv);
	if (all->table->number_of_times_each_philosopher_must_eat > 200 || all->table->number_of_times_each_philosopher_must_eat == 0)
		return (0);
	printf("Time to die = [%ld]\n",all->table->time_to_eat);
	set_dinner(all,argc,argv);
	join_and_destroy_mutex(all);
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
