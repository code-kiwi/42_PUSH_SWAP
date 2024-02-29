/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:14 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 17:56:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prepend_chars(char *str, char c, size_t len_total)
{
	char	*res;
	size_t	len_str;

	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	if (len_str >= len_total)
		return (ft_strdup(str));
	res = ft_calloc(len_total + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memset(res, c, len_total - len_str);
	ft_strlcat(res, str, len_total + 1);
	return (res);
}
