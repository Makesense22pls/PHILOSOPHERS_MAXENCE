/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:51:43 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/07 17:52:17 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long elapsed_time(struct timeval start_time) 
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return ((current_time.tv_sec - start_time.tv_sec) * 1000 + 
            (current_time.tv_usec - start_time.tv_usec) / 1000);
}

int elapsed_time_meal(t_philo *data) 
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return ((current_time.tv_sec - data->last_meal.tv_sec) * 1000 + 
            (current_time.tv_usec - data->last_meal.tv_usec) / 1000);
}

int check_if_only_one_philo(t_philo *all)
{
    if (all->number_of_philosophers == 1)
    {
        printf("Philosophe n°1 is thinking\n");
        usleep(all->table->time_to_die);
        printf("Philosophe n°1 is dead\n");
        return (1);
    }
    return (0);
}