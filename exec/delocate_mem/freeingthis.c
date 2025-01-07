/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeingthis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:28:37 by mafourni          #+#    #+#             */
/*   Updated: 2025/01/07 18:33:08 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

void ft_free(t_philo *all)
{
    free(all->table);
    free(all->philo_threads);
    free(all->fork);
    free(all);
}