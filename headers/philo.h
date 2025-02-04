/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:55:18 by codespace         #+#    #+#             */
/*   Updated: 2025/02/04 04:21:39 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	int				max;
	long			start_time;
	int				dead;
	int				all_ready;
}					t_table;

typedef struct s_philo
{
	pthread_t		ph_thread;
	int				belly_full;
	int				nb_meal_eat;
	int				index;
	long			last_meal;
	int				number_of_philosophers;
	t_table			*table;
}					t_philo;

// PARSING
long long int		ft_atoi(char *str);
bool				parser(int argc, char **str);
bool				ft_isdigit_philo(char **str, int argc);
char				*ft_itoa(int n);
int					ft_len(int nb);
int					ft_strncmp(const char *s1, const char *s2);

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
void				dead_guy(t_philo *philos, int i);

// TIME
void				smart_sleep(long milliseconds, t_philo *philo);
void				ft_usleep(long milliseconds);

long				get_time(void);

// PRINT
void				print(t_philo *philo, char *txt);

//FREE
void				free_destroy(t_table *all, t_philo *philo);

// NORMINETTE
void				wait_norminette(t_philo *philo);
void				init_norminette(int i, t_table *info, t_philo *philo);

//get and set
int					getter(pthread_mutex_t *mtx, int *i);
void				setter(pthread_mutex_t *mtx, int *i, int new);

#endif