/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 00:56:56 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int main(int argc, char **argv)
{
	t_philo *philo;
	t_table *all;

	if (parser(argc, argv) == 0)
		return (1);
	all = initialize(argc, argv);
	if(!all)
		return (1);
	if (innit_philo_mutex(all) != 0)
		return (1);
	philo = set_table(all);
	if (!philo)
		return (1);
	pthread_t	monitor_thread;
	pthread_create(&monitor_thread, NULL, monitor, philo);
	// pthread_join(monitor_thread, NULL);
	pthread_join(monitor_thread, NULL);
	int i = 0;
	while(i < all->num_philo)
	{
		pthread_join(philo[i].ph_thread, NULL);
		i++;
	}
	free(all->forks);
	free(all);
	free(philo);
	return (0);
}
