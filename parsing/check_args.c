/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:33:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/24 05:57:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

bool	ft_isdigit_philo(char **str,int argc)
{
	//printf("argc there [%d] = \n", argc);
	while(argc > 1)
	{	
	//	printf("IN 2 \n");
		int i = 0;
		argc--;
		//printf("str[argc] = [%s]",str[argc]);
		while(str[argc][i] != '\0')
		{
			//printf("IN 3 \n");
			if (( str[argc][i]>= 48 && str[argc][i]<= 57) || str[argc][i]== 32)
				i++;
			else
				return (false);
			//printf("IN 4 \n");
		}
	}
	return (true);
}