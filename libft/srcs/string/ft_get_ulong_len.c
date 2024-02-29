/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ulong_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:23:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 12:29:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_ulong_len(unsigned long nb, size_t base_len)
{
	size_t			size;

	size = 1;
	while (nb / base_len > 0)
	{
		size++;
		nb /= base_len;
	}
	return (size);
}
