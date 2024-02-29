/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:55 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:08:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		return (0 - *s2);
	else if (s2 == NULL)
		return (*s1);
	s1_char = (unsigned char *) s1;
	s2_char = (unsigned char *) s2;
	i = 0;
	while (s1_char[i] != '\0' && s2_char[i] != '\0' && i < n)
	{
		if (s1_char[i] != s2_char[i])
			return (s1_char[i] - s2_char[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1_char[i] - s2_char[i]);
}
