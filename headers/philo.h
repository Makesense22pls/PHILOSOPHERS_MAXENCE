/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:55:18 by codespace         #+#    #+#             */
/*   Updated: 2025/01/01 22:13:54 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct  s_table
{
    long int time_to_die;
    long int time_to_eat;
    long int time_to_sleep;
    long int number_of_times_each_philosopher_must_eat;
    pthread_mutex_t death_mutex;
    int someone_died;
    int all_ate_enough;
    
}t_table;

typedef struct s_shared_data {
    int philosopher_dead;
    pthread_mutex_t death_mutex;
} t_shared_data;

typedef struct s_philo
{
    int MAX;
    int TEST;
    int index;
    struct timeval last_meal;
    int num_philo;
    pthread_t *philo_threads;
    int mail;
    pthread_mutex_t                 *fork;
    int								argc;
    char                        **input;
    long int number_of_philosophers;
    long int meals_count;
    long int number_of_times_each_philosopher_must_eat;
    t_table *table;
}			t_philo;



bool        ft_isdigit_philo(char **str, int argc);
t_philo	    *initialize(int argc, char **argv);
void	*routine(void *struc);
int		thread_join(t_philo *all);
void dinner_start(t_philo *all);
void	innit_philo_mutex(t_philo *init, int argc, char **argv);
void	innit_philo_threads(t_philo *init, int argc, char **argv);
int		join_and_destroy_mutex(t_philo *all);
void	set_dinner(t_philo *init, int argc, char **argv);
int check_if_only_one_philo(t_philo *all);
long elapsed_time(struct timeval start_time) ;
int elapsed_time_meal(t_philo *data) ;