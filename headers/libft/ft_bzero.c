/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:34:15 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/21 18:42:38 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_;

	s_ = (unsigned char *) s;
	if (!s || n == 0)
		return ;
	while (n--)
	{
		*s_++ = '\0';
	}
}
