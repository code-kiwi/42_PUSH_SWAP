/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:54 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:24:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*char_ptr;
	unsigned char	char_value;

	if (s == NULL)
		return (NULL);
	char_ptr = (unsigned char *) s;
	char_value = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		char_ptr[i] = char_value;
		i++;
	}
	return (s);
}
