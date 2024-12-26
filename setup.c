/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:28:29 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 14:53:07 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

// t_input	*ft_innit(int argc, char **argv)
// {
// 	t_input	*init;
// 	init = malloc(sizeof(t_input));
// 	if (!init)
// 		return (NULL);
// 	init->table = malloc(sizeof(t_table));
// 	if (!init->table)
// 		return (NULL);
// 	init->mail = 0;
// 	init->argc  = argc;
// 	init->input = argv;
// 	init->number_of_philosophers = ft_atoi(argv[1]);
//     init->table->time_to_die =  ft_atoi(argv[2]);
//     init->table->time_to_eat = ft_atoi(argv[3]);
//     init->table->time_to_sleep = ft_atoi(argv[4]);
//     if (argc == 6)
// 		init->table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
// 	return (init);
// }