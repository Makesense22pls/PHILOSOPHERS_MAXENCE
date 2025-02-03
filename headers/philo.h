/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:55:18 by codespace         #+#    #+#             */
/*   Updated: 2025/02/04 00:14:40 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_nb;
	long			start_time;
	int				dead;
}					t_table;

typedef struct s_philo
{
	pthread_t		ph_thread;
	int				belly_full;
	int				nb_meal_eat;
	int				index;
	long			last_meal;
	int				argc;
	int				number_of_philosophers;
	t_table			*table;
}					t_philo;

// PARSING
long long int		ft_atoi(char *str);
bool				parser(int argc, char **str);
bool				ft_isdigit_philo(char **str, int argc);

// INIT
t_table				*initialize(int argc, char **argv);
int					innit_philo_mutex(t_table *table);

// DINNER
t_philo				*set_table(t_table *info);

// ROUTINE
void				*routine(void *struc);
void				*philo_1_routine(void *arg);
void				take_eat_release(t_philo *philo);
void				eat(t_philo *philo);
void				release_forks(t_philo *philo);
void				take_forks(t_philo *philo);
void				sleep_and_think(t_philo *philo);

// DEATH CHECK
void				*monitor(void *arg);

// TIME
long int			elapsed_time(t_philo *philo);
void				ft_usleep(long milliseconds);
long				get_time(void);

//PRINT
void				print(t_philo *philo, char *txt);

// NORMINETTE
void				init_norminette(int i, t_table *info, t_philo *philo);
void				dead_guy(t_philo *philos, int i);
void	smart_sleep(long milliseconds, t_philo *philo);	