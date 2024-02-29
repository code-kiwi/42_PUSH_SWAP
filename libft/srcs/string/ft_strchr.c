/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:34 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:11:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*res;
	unsigned char	c_char;

	if (s == NULL)
		return (NULL);
	res = (char *) s;
	c_char = (unsigned char) c;
	while (*res != '\0')
	{
		if (*res == c_char)
			return (res);
		res++;
	}
	if (*res == c_char)
		return (res);
	return (NULL);
}
