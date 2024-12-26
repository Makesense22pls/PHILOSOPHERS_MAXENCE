/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:55:18 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 19:41:59 by codespace        ###   ########.fr       */
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
    
}t_table;

typedef struct s_input
{
    int mail;
    pthread_mutex_t                 mutex;
    int								argc;
    char                        **input;
    long int number_of_philosophers;
	long int last_meal;
    long int meals_count;
    long int number_of_times_each_philosopher_must_eat;
    t_table *table;
}			t_input;



bool        ft_isdigit_philo(char **str, int argc);
t_input	    *ft_innit(int argc, char **argv);
void	*routine(void *struc);
int		ft_thread(t_input *all);
void dinner_start(t_input *all);