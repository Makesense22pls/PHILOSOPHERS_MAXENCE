/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/01/27 21:33:34 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


int main(int argc, char **argv)
{
	t_philo *philo;
	t_table *all;
	if (parser(argc, argv) == 0)
		return (0);
	all = initialize(argc, argv);
	philo = set_table(all,argc,argv);
	if (philo == NULL)
		return (printf("Failed to create philo\n"), -1);
	monitor(philo);
	// join_and_destroy_mutex(all);
	// ft_free(all);
	return (0);
}
