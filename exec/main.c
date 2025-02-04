/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/02/04 03:49:20 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_table	*all;
	int		i;

	if (parser(argc, argv) == 0)
		return (1);
	all = initialize(argc, argv);
	if (!all)
		return (1);
	if (innit_philo_mutex(all) != 0)
		return (1);
	philo = set_table(all);
	if (!philo)
		return (1);
	i = 0;
	while (i < all->num_philo)
	{
		pthread_join(philo[i].ph_thread, NULL);
		i++;
	}
	free_destroy(all, philo);
	return (0);
}

void	free_destroy(t_table *all, t_philo *philo)
{
	int	i;

	pthread_mutex_destroy(&all->meal_lock);
	pthread_mutex_destroy(&all->dead_lock);
	pthread_mutex_destroy(&all->print_lock);
	i = 0;
	while (i < all->num_philo)
	{
		pthread_mutex_destroy(&all->forks[i]);
		i++;
	}
	free(all->forks);
	free(all);
	free(philo);
}
