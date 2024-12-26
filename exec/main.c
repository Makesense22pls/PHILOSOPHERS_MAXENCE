/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 18:14:19 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int main(int argc, char **argv)
{
	t_philo *all;
	int i;
	(void) i;
	if (argc != 6 && argc != 5)
		return (printf("Wrong numbers of args\n"), 0);
	if (ft_isdigit_philo(argv,argc) == 0)
		return(printf("Only numbers accepted"), 0);
	all = initialize(argc, argv);
	if (all->table->number_of_times_each_philosopher_must_eat > 200 || all->table->time_to_die < 0 || all->table->time_to_eat < 0 || all->table->time_to_sleep < 0)
		return (0);
	printf("GOOD1\n");
	dinner_start(all);
}

t_philo	*initialize(int argc, char **argv)
{
	t_philo	*init;
	init = malloc(sizeof(t_philo));
	if (!init)
		return (NULL);
	init->table = malloc(sizeof(t_table));
	if (!init->table)
		return (NULL);
	init->num_philo = 0;
	init->mail = 0;
	init->argc  = argc;
    init->table->time_to_die =  ft_atoi(argv[2]) * 1e3;
    init->table->time_to_eat = ft_atoi(argv[3]) * 1e3;
    init->table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
    if (argc == 6)
		init->table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		init->table->number_of_times_each_philosopher_must_eat = -1;
	innit_philo_threads(init,argc,argv);
	return (init);
}

void	innit_philo_threads(t_philo *init, int argc, char **argv)
{
	(void) argc;
	init->number_of_philosophers = ft_atoi(argv[1]);
	init->philo_threads = malloc(sizeof(pthread_t) * init->number_of_philosophers);
	if (!init->philo_threads)
		return;
	innit_philo_mutex(init,argc, argv);
	gettimeofday(&init->last_meal, NULL);
	while(init->num_philo < init->number_of_philosophers)
		{
			t_philo *philo = malloc(sizeof(t_philo));
        	*philo = *init;
       		philo->index = init->num_philo;
			if(pthread_create(&init->philo_threads[init->num_philo], NULL, (void *)routine, (void *)philo) != 0)
			{
				printf("Failed to create a philo\n");
				return;
			}
			init->num_philo++;
			printf("Philo n°[%d] has started exec\n",init->num_philo);
		}
}

void	innit_philo_mutex(t_philo *init, int argc, char **argv)
{
	int i = 0;
	(void) argc;
	(void) argv;
	init->fork = malloc(sizeof(pthread_mutex_t) * init->number_of_philosophers);
	if (!init->fork)
		return;
	while(i < init->number_of_philosophers)
		{	
			if (pthread_mutex_init(&init->fork[i], NULL) != 0)
            {
				printf("Failed to initialize mutex\n");
				return;
			}
			i++;
		}
}