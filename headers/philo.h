/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:55:18 by codespace         #+#    #+#             */
/*   Updated: 2025/01/22 18:15:11 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

 

typedef struct  s_table
{
	
	long int											num_philo;
    int													time_to_die;
    int													time_to_eat;
    int													time_to_sleep;
	long												start_time;
    long int											number_of_times_each_philosopher_must_eat;
	pthread_mutex_t										*forks;
    pthread_mutex_t										meal_lock;
    long int 											someone_died;
    long int											all_ate_enough;
}t_table;

typedef struct s_philo
{
	pthread_t ph_thread;
    int     nb_meal_eat;
    long						last_meal;
    long int					index;
    long int					mail;
    long int					argc;
    long int			number_of_philosophers;
    t_table				*table;
}			t_philo;

//PARSING 
bool parser(int argc, char **str);
bool        ft_isdigit_philo(char **str, int argc);
int			check_if_only_one_philo(t_philo *all);
//INIT
t_table    *initialize(int argc, char **argv);
int			join_and_destroy_mutex(t_philo *all);
void	innit_philo_mutex(t_table *init, int argc, char **argv);


//DINNER
void	*routine(void *struc);
t_philo	*set_table(t_table *info, int argc, char **argv);

//TIME
long int    elapsed_time(t_philo *philo);

long	get_time(void);

//FREE
void ft_free(t_philo *all);

void	*monitor(void *arg);