/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:55:18 by codespace         #+#    #+#             */
/*   Updated: 2025/01/28 23:16:29 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_table
{
	pthread_mutex_t										*forks;
    pthread_mutex_t										print_lock;
    pthread_mutex_t										meal_lock;
	int													num_philo;
    int													time_to_die;
    int													time_to_eat;
    int													time_to_sleep;
    int													must_eat_nb;
	long												start_time;
}t_table;

typedef struct s_philo
{
	pthread_t					ph_thread;
	int							belly_full;
    int							nb_meal_eat;
    int							index;
    long						last_meal;
    int					argc;
    int					number_of_philosophers;
    t_table				*table;
}t_philo;

//PARSING 
bool 		parser(int argc, char **str);
bool	ft_isdigit_philo(char **str, int argc);
// int		check_if_only_one_philo(t_philo *all); we may use it

//INIT
t_table		*initialize(int argc, char **argv);
int			innit_philo_mutex(t_table *table);

//DINNER
t_philo	*set_table(t_table *info);

//ROUTINE
void	*routine(void *struc);
void	routine_without_max(t_philo *philo);
void	routine_with_max(t_philo *philo);

void	eat(t_philo *philo);
void	release_forks(t_philo *philo);
void	take_forks(t_philo *philo);

//DEATH CHECK
void	*monitor(void *arg);

//TIME
long int	elapsed_time(t_philo *philo);
void		ft_usleep(long milliseconds);
long		get_time(void);


//U KNOW
void	print(t_philo *philo, char *txt);