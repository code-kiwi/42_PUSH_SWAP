/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:45 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:04:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	returned_val;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	while (dst[i] != '\0')
		i++;
	if (i > size)
		returned_val = ft_strlen(src) + size;
	else
		returned_val = i + ft_strlen(src);
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (returned_val);
}
