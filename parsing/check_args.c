/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:33:39 by codespace         #+#    #+#             */
/*   Updated: 2025/01/10 14:24:42 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

bool parser(int argc, char **str)
{
	if (argc != 6 && argc != 5)
		return (printf("Wrong numbers of args\n"), false);
	if (ft_isdigit_philo(str,argc) == false)
		return(printf("Only positive numbers accepted"), false);
	if (str[5] != NULL)
	{
		if (ft_atoi(str[5]) > 200 || ft_atoi(str[5]) == 0)
			return (printf("Unaceptable numbers in [number_of_times_each_philosopher_must_eat]\n"), false);
	}
	return (true);
}
bool	ft_isdigit_philo(char **str,int argc)
{
	while(argc > 1)
	{
		int i = 0;
		argc--;
		while(str[argc][i] != '\0')
		{
			if (( str[argc][i]>= 48 && str[argc][i]<= 57) || str[argc][i]== 32)
				i++;
			else
				return (false);
		}
	}
	return (true);
}
int check_if_only_one_philo(t_philo *all)
{
    if (all->number_of_philosophers == 1)
    {
        printf("Philosophe n°1 is thinking\n");
        usleep(all->table->time_to_die);
        printf("Philosophe n°1 is dead\n");
        return (1);
    }
    return (0);
}