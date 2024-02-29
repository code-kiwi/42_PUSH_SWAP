/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:02 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/28 10:29:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_putnbr_fd_recursion(long nb, int fd)
{
	ssize_t	count;
	ssize_t	returned;

	count = 0;
	if (nb == 0)
		return (0);
	returned = ft_putnbr_fd_recursion(nb / 10, fd);
	if (returned == -1)
		return (-1);
	count += returned;
	returned = ft_putchar_fd(nb % 10 + '0', fd);
	if (returned == -1)
		return (-1);
	return (count + returned);
}

ssize_t	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	ssize_t	count;
	ssize_t	returned;

	count = 0;
	nb = (long) n;
	if (nb == 0)
		return (ft_putchar_fd('0', fd));
	if (nb < 0)
	{
		returned = ft_putchar_fd('-', fd);
		if (count == -1)
			return (-1);
		nb *= -1;
		count += returned;
	}
	returned = ft_putnbr_fd_recursion(nb, fd);
	if (returned == -1)
		return (-1);
	return (count + returned);
}
