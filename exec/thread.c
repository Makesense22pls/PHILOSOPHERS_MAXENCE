/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 06:57:33 by codespace         #+#    #+#             */
/*   Updated: 2025/01/23 19:14:52 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

t_philo	*set_table(t_table *info, int argc, char **argv)
{
	(void) argc;
    int i = 0;
	t_philo	*philo;
	philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!philo)
    	return(NULL);
	innit_philo_mutex(info,argc, argv);
	while(i < info->num_philo)
	{
		philo[i].nb_meal_eat = 0;
    	philo[i].index = i;
		philo[i].table = info;
		philo[i].last_meal = info->start_time;
		if(pthread_create(&philo[i].ph_thread, NULL, (void *)routine, &philo[i]) != 0)
		{
			printf("Failed to create a philo\n");
			return(NULL);
		}
		i++;
	}
	return (philo);
}

void	*routine(void *arg) 
{
    t_philo *philo = (t_philo *)arg;

	int i = 0;
	if (philo->index % 2 != 0)
        usleep(100);
    while (1)
    {
        if (philo->index % 2 == 0)
        {
            pthread_mutex_lock(&philo->table->forks[philo->index]);
            printf("[%ld ms] Philosophe n°%ld has taken a fork\n", elapsed_time(philo), philo->index + 1);
            pthread_mutex_lock(&philo->table->forks[(philo->index + 1) % philo->table->num_philo]);
            printf("[%ld ms] Philosophe n°%ld has taken a fork\n", elapsed_time(philo), philo->index + 1);
        } 
        else
        {
            pthread_mutex_lock(&philo->table->forks[(philo->index + 1) % philo->table->num_philo]);
            printf("[%ld ms] Philosophe n°%ld has taken a fork\n", elapsed_time(philo), philo->index + 1);
            pthread_mutex_lock(&philo->table->forks[philo->index]);
            printf("[%ld ms] Philosophe n°%ld has taken a fork\n", elapsed_time(philo), philo->index + 1);
        }

        printf("[%ld ms] Philosophe n°%ld is eating, Compteur de manger = [%d]\n", elapsed_time(philo), philo->index + 1, i++);
        usleep(philo->table->time_to_eat * 1e3);
        philo->last_meal = get_time();
		philo->nb_meal_eat++;
		
        pthread_mutex_unlock(&philo->table->forks[philo->index]);
        pthread_mutex_unlock(&philo->table->forks[(philo->index + 1) % philo->table->num_philo]);
		if(philo->nb_meal_eat == philo->table->number_of_times_each_philosopher_must_eat)
			break;
        printf("[%ld ms] Philosophe n°%ld is sleeping\n", elapsed_time(philo), philo->index + 1);
        usleep(philo->table->time_to_sleep * 1e3);
        printf("[%ld ms] Philosophe n°%ld is thinking\n", elapsed_time(philo), philo->index + 1);
    }
    return (NULL);
}

void *monitor(void *arg)
{
    t_philo *philos = (t_philo *)arg;
    int i;
    int belly_is_full;

    while (1)
    {
        i = 0;
        belly_is_full = 1;
        while (i < philos->table->num_philo)
        {
            long time_since_last_meal = get_time() - philos[i].last_meal;
            
            if (time_since_last_meal > philos->table->time_to_die)
            {
                printf("[%ld ms] Philosophe n°%ld died\n", 
                    get_time() - philos->table->start_time, 
                    philos[i].index + 1);
                return (NULL);
            }
            
            if (philos->table->number_of_times_each_philosopher_must_eat > 0 && 
                philos[i].nb_meal_eat < philos->table->number_of_times_each_philosopher_must_eat)
            {
                belly_is_full = 0;
            }
            i++;
        }
        
        if (belly_is_full && philos->table->number_of_times_each_philosopher_must_eat > 0)
        {
            printf("They choose to stop eating\n");
            return (NULL);
        }
        usleep(100);
    }
    return (NULL);
}

// void	*monitor(void *arg)
// {
// 	t_philo	*philos;
// 	int		i;
// 	int		belly_is_full;

// 	belly_is_full = 0;	

// 	philos = (t_philo *)arg;
// 	while (1)
// 	{
// 		i = 0;
// 		belly_is_full = 1;
// 		while (i < philos->table->num_philo)
// 		{
// 			// int p = get_time() - philos[i].last_meal;
// 			if (get_time() - philos[i].last_meal > philos->table->time_to_die)
// 			{
// 				// printf(" OUT = [%d]\n", p);
// 				// printf("time to die = [%d]\n\n || ",philos->table->time_to_die);
// 				printf("[%ld ms] Philosophe n°%ld died\n", elapsed_time(philos), philos->index + 1);
// 				exit(0);
// 			}
// 			if (philos->table->number_of_times_each_philosopher_must_eat > 0 && 
// 				philos[i].nb_meal_eat < philos->table->number_of_times_each_philosopher_must_eat)
// 			{
// 				belly_is_full= 0;
// 			}
// 			i++;
// 		}
// 		if (belly_is_full && philos->table->number_of_times_each_philosopher_must_eat > 0)
// 		{
// 			printf("They choose to stope eating to stop getting bigger\n");
// 			exit(0);
// 		}
// 		usleep(1000);
// 	}
// 	return (NULL);
// }
