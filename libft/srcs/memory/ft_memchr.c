/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:43 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:21:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_char;
	unsigned char	*s_char;

	if (s == NULL)
		return (NULL);
	c_char = (unsigned char) c;
	s_char = (unsigned char *) s;
	while (n > 0)
	{
		if (*s_char == c_char)
			return ((void *) s_char);
		s_char++;
		n--;
	}
	return (NULL);
}
