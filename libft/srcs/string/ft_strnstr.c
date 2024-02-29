/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:58 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:09:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_starts_with(char *str, char *to_find)
{
	while (*str && *to_find && *str == *to_find)
	{
		str++;
		to_find++;
	}
	if (*str == *to_find || *to_find == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	char	*big_str;
	char	*little_str;

	if (little == NULL)
		return ((char *) big);
	if (big == NULL)
		return (NULL);
	i = 0;
	big_str = (char *) big;
	little_str = (char *) little;
	little_len = ft_strlen(little_str);
	if (little_len == 0)
		return (big_str);
	while (big_str[i] != '\0' && i + little_len <= len)
	{
		if (str_starts_with(big_str + i, little_str))
			return (big_str + i);
		i++;
	}
	return (NULL);
}
