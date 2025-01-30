/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:10:14 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/30 22:37:16 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	print(t_philo *philo, char *txt)
{
	long	timestamp;

	timestamp = get_time() - philo->table->start_time;
	printf("[%ld ms] Philo n°%d %s\n", timestamp, philo->index, txt);
}
