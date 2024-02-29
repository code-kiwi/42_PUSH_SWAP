/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 15:39:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nb_ptr)
{
	long	res;
	int		sign;

	if (nb_ptr == NULL)
		return (0);
	res = 0;
	while (ft_isspace(*nb_ptr))
		nb_ptr++;
	sign = 1;
	if (*nb_ptr == '+')
		nb_ptr++;
	else if (*nb_ptr == '-')
	{
		nb_ptr++;
		sign *= -1;
	}
	while (ft_isdigit(*nb_ptr))
	{
		res = res * 10 + ((long)(*nb_ptr - '0'));
		nb_ptr++;
	}
	return (sign * res);
}
