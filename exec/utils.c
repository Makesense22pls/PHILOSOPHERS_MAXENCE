/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:10:14 by mafourni          #+#    #+#             */
/*   Updated: 2025/02/04 04:48:33 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	print(t_philo *philo, char *txt)
{
	long	timestamp;

	if (getter(&philo->table->dead_lock, &philo->table->dead))
		return ;
	timestamp = get_time() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_lock);
	if (!getter(&philo->table->dead_lock, &philo->table->dead))
		printf("%ld %d %s\n", timestamp, philo->index, txt);
	pthread_mutex_unlock(&philo->table->print_lock);
}

int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		len++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*copy;
	int		len;
	long	nb;

	nb = n;
	len = ft_len(nb);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	if (nb == 0)
		copy[0] = '0';
	if (n < 0)
	{
		copy[0] = '-';
		nb = -nb;
	}
	copy[len--] = '\0';
	while (nb != 0)
	{
		copy[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (copy);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
