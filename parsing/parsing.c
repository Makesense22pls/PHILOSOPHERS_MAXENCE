/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:33:39 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 22:36:59 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

bool	parser(int argc, char **str)
{
	if (argc != 6 && argc != 5)
		return (printf("Wrong numbers of args\n"), false);
	if (ft_isdigit_philo(str, argc) == false)
		return (printf("Only positive numbers accepted"), false);
	if (str[5] != NULL)
	{
		if (ft_atoi(str[5]) > 200 || ft_atoi(str[5]) == 0)
			return (printf("Unaceptable numbers in [must_eat_nb]\n"), false);
	}
	return (true);
}
bool	ft_isdigit_philo(char **str, int argc)
{
	int	i;

	while (argc > 1)
	{
		i = 0;
		argc--;
		while (str[argc][i] != '\0')
		{
			if ((str[argc][i] >= 48 && str[argc][i] <= 57)
				|| str[argc][i] == 32)
				i++;
			else
				return (false);
		}
	}
	return (true);
}
long long int	ft_atoi(char *str)
{
	long long int	result;
	long long int	comptesign;

	result = 0;
	comptesign = 1;
	if (!str)
		return (0);
	while ((str[0] >= 9 && str[0] <= 13) || str[0] == 32)
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			comptesign = -1;
		str++;
	}
	while (str[0] >= '0' && str[0] <= '9')
	{
		result = result * 10 + (str[0] - '0');
		str++;
	}
	return (result * comptesign);
}
