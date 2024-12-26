/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 19:45:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int main(int argc, char **argv)
{
	t_input *all;
	int i;
	(void) i;
	if (argc != 6 && argc != 5)
		return (printf("Wrong numbers of args\n"), 0);
	if (ft_isdigit_philo(argv,argc) == 0)
		return(printf("Only numbers accepted"), 0);
	all = ft_innit(argc, argv);
	if (all->table->number_of_times_each_philosopher_must_eat > 200 || all->table->time_to_die < 0 || all->table->time_to_eat < 0 || all->table->time_to_sleep < 0)
		return (0);
	//printf("GOOD\n");
	dinner_start(all);
}
