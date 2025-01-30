/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 22:35:18 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

t_philo	*set_table(t_table *info)
{
	int			i;
	t_philo		*philo;
	pthread_t	monitor_thread;

	philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		init_norminette(i, info, philo);
		if (info->num_philo == 1)
			pthread_create(&philo[i].ph_thread, NULL, philo_1_routine, &philo[i]);
		if (info->num_philo > 1)
		{
			if (pthread_create(&philo[i].ph_thread, NULL, routine, &philo[i]) != 0)
				return (NULL);
		}
	}
	pthread_create(&monitor_thread, NULL, monitor, philo);
	pthread_join(monitor_thread, NULL);
	return (philo);
}

void init_norminette(int i, t_table *info, t_philo *philo)
{
	philo[i].table = info;
	philo[i].belly_full = 0;
	philo[i].nb_meal_eat = 0;
	philo[i].index = i + 1;
	philo[i].last_meal = info->start_time;
}