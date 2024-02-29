/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:51 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:23:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (src < dest)
	{
		dest_char = (unsigned char *) dest;
		src_char = (unsigned char *) src;
		while (n > 0)
		{
			*(dest_char + n - 1) = *(src_char + n - 1);
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
