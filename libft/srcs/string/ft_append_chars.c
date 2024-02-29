/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:14 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/09 17:59:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_chars(char *str, char c, size_t len_total)
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
	ft_strlcpy(res, str, len_total + 1);
	ft_memset(res + len_str, c, len_total - len_str);
	return (res);
}
