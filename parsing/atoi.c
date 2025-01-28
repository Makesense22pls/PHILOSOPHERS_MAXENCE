/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:35:58 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/28 22:36:18 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

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
		str ++;
	}
	return (result * comptesign);
}