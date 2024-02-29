/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:10:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/15 19:05:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(int c)
{
	char	*res;

	res = (char *) ft_calloc(2, sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = c;
	return (res);
}
