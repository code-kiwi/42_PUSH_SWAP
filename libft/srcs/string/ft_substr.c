/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/13 10:33:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*s_end;
	char	*s_start;
	size_t	tmp_len;

	if (s == NULL)
		return (NULL);
	s_start = (char *) s;
	tmp_len = ft_strlen(s_start);
	if (start > tmp_len)
		return (ft_strdup(""));
	s_start += start;
	s_end = s_start;
	while (*s_end != '\0' && ((unsigned int)(s_end - s_start) < len))
		s_end++;
	tmp_len = s_end - s_start;
	res = (char *) malloc((tmp_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s_start, tmp_len + 1);
	return (res);
}
