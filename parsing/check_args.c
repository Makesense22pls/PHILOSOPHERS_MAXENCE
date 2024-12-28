/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:33:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 18:24:19 by maxencefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

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