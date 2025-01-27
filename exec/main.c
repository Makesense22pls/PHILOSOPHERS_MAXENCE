/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:44 by codespace         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/27 19:43:23 by mafourni         ###   ########.fr       */
=======
/*   Updated: 2025/01/23 19:16:28 by mafourni         ###   ########.fr       */
>>>>>>> ae30ff1ff79c8d87ffcec643695db8a2bd4eb0ce
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
<<<<<<< HEAD
	// join_and_destroy_mutex(all);
	// ft_free(all);
	return (0);
}
=======
	// ft_free(all);
	return (0);
}
>>>>>>> ae30ff1ff79c8d87ffcec643695db8a2bd4eb0ce
