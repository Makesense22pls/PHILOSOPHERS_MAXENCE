/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/01/07 18:36:56 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int main(int argc, char **argv)
{
	t_philo *all;
	// int i;
	// i = 0;
	if (parser(argc, argv) == 0)
		return (0);
	all = initialize(argc, argv);
	set_table(all,argc,argv);
	join_and_destroy_mutex(all);
	//printf("---- OE :LA TEAM ----\n");
	ft_free(all);
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
