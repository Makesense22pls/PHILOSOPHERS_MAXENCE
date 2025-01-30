/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 22:12:11 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

// void	print_meal_stats(t_philo *philo, t_table *table)
// {
// 	int	i;

// 	printf("\n=== Meal Statistics ===\n");
// 	for (i = 0; i < table->num_philo; i++)
// 	{
// 		printf("Philosopher %d ate %d times\n", philo[i].index,
// 			philo[i].nb_meal_eat);
// 	}
// 	printf("=====================\n");
// }

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
	// print_meal_stats(philo, all);
	free(all->forks);
	free(all);
	free(philo);
	return (0);
}
