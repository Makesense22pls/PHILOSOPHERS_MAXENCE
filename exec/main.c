/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
/*   Updated: 2025/01/28 23:22:03 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


int main(int argc, char **argv)
{
	t_philo *philo;
	t_table *all;

	if (parser(argc, argv) == 0)
		return (1);
	all = initialize(argc, argv);
	if(!all)
		return (NULL);
	if (innit_philo_mutex(all) != 0)
		return (1);
	philo = set_table(all);
	if (!philo)
		return (NULL);
	monitor(philo);
	return (0);
}
