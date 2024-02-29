/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:28 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/18 16:23:50 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char *delim)
{
	char	in_word;
	size_t	count;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (!in_word && ft_strchr(delim, *s) == NULL)
		{
			in_word = 1;
			count++;
		}
		else if (in_word && ft_strchr(delim, *s) != NULL)
			in_word = 0;
		s++;
	}
	return (count);
}
