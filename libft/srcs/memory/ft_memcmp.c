/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:45 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:24:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *) s1;
	s2_char = (unsigned char *) s2;
	if (s1_char == NULL && s2_char == NULL)
		return (0);
	else if (s1_char == NULL)
		return (0 - *s2_char);
	else if (s2_char == NULL)
		return (*s1_char);
	while (n > 0)
	{
		if (*s1_char != *s2_char)
			return (*s1_char - *s2_char);
		s1_char++;
		s2_char++;
		n--;
	}
	return (0);
}
