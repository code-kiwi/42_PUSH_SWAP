/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 15:47:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atoul(const char *nb_ptr)
{
	unsigned long	res;

	if (nb_ptr == NULL)
		return (0);
	res = 0;
	while (ft_isspace(*nb_ptr))
		nb_ptr++;
	if (*nb_ptr == '+')
		nb_ptr++;
	while (ft_isdigit(*nb_ptr))
	{
		res = res * 10 + ((unsigned long)(*nb_ptr - '0'));
		nb_ptr++;
	}
	return (res);
}
