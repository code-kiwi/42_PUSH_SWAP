/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:17:16 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 12:53:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_valid_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (false);
	i = 0;
	while (i < base_len)
	{
		if (!ft_isprint(base[i]) || base[i] == ' ')
			return (false);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
