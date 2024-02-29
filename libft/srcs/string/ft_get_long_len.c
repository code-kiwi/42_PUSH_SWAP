/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_long_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:23:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 12:23:24 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_long_len(long num, size_t base_len)
{
	size_t			size;
	unsigned long	nb;

	size = 1;
	if (num < 0)
	{
		nb = (unsigned long) -1 * num;
		size++;
	}
	else
		nb = (unsigned long) num;
	while (nb / base_len > 0)
	{
		size++;
		nb /= base_len;
	}
	return (size);
}
