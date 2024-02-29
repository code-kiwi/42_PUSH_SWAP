/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:17:16 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 12:51:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long nb, char *base)
{
	char	*res;
	size_t	len_base;
	size_t	len_res;
	size_t	i;

	if (base == NULL || !ft_is_valid_base(base))
		return (NULL);
	if (nb == 0)
		return (ft_ctoa(base[0]));
	len_base = ft_strlen(base);
	len_res = ft_get_ulong_len(nb, len_base);
	res = (char *) ft_calloc(len_res + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = len_res - 1;
	while (nb > 0)
	{
		res[i] = base[nb % len_base];
		i--;
		nb /= len_base;
	}
	return (res);
}
