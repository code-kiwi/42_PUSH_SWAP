/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:21:16 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/18 15:11:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*pos = NULL;

	if (delim == NULL || *delim == '\0')
		return (str);
	if (str != NULL)
		pos = str;
	else
		str = (char *) pos;
	if (pos == NULL || *pos == '\0')
	{
		pos = NULL;
		return (NULL);
	}
	while (*pos != '\0' && !ft_strchr(delim, *pos))
		pos++;
	while (*pos != '\0' && ft_strchr(delim, *pos))
	{
		*pos = '\0';
		pos++;
	}
	return (str);
}
