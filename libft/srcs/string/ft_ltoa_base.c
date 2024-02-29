/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:17:16 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 12:51:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract_number_base(char *res, size_t len_res, long nb, char *base)
{
	unsigned long	num;
	size_t			i;
	size_t			len_base;

	if (nb < 0)
		num = (unsigned long) -1 * nb;
	else
		num = (unsigned long) nb;
	len_base = ft_strlen(base);
	i = len_res - 1;
	while (num > 0)
	{
		res[i] = base[num % len_base];
		i--;
		num /= len_base;
	}
	if (nb < 0)
		res[0] = '-';
}

char	*ft_ltoa_base(long nb, char *base)
{
	char	*res;
	size_t	len_base;
	size_t	len_res;

	if (base == NULL || !ft_is_valid_base(base))
		return (NULL);
	if (nb == 0)
		return (ft_ctoa(base[0]));
	len_base = ft_strlen(base);
	len_res = ft_get_long_len(nb, len_base);
	res = (char *) ft_calloc(len_res + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	extract_number_base(res, len_res, nb, base);
	return (res);
}
