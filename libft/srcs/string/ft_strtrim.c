/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:02 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 18:15:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = (char *) s1;
	while (*start != '\0' && ft_strchr(set, (int) *start))
		start++;
	end = start;
	while (*end != '\0')
		end++;
	end--;
	while (ft_strchr(set, (int) *end))
		end--;
	res = ft_substr((const char *) start, 0, (end - start + 1));
	return (res);
}
