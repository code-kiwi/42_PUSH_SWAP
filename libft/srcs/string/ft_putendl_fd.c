/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:59 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/28 10:14:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	returned;
	ssize_t	count;

	count = 0;
	if (s != NULL)
	{
		returned = ft_putstr_fd(s, fd);
		if (returned == -1)
			return (-1);
		count += returned;
		returned = ft_putchar_fd('\n', fd);
		if (returned == -1)
			return (-1);
		count += returned;
	}
	return (count);
}
