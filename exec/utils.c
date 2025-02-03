/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:10:14 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/04 00:08:37 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	print(t_philo *philo, char *txt)
{
	long	timestamp;

	if (philo->table->dead)
		return ;
	timestamp = get_time() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_lock);
	printf("[%ld ms] Philo n°%d %s\n", timestamp, philo->index, txt);
	pthread_mutex_unlock(&philo->table->print_lock);
}
