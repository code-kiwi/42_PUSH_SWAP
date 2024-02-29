/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:28 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/18 16:22:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_extract_words(
	const char *s, char *delim, char **res, size_t nb_words
)
{
	size_t	i;
	size_t	j;
	size_t	index_res;

	index_res = 0;
	i = 0;
	while (index_res < nb_words)
	{
		while (s[i] != '\0' && ft_strchr(delim, s[i]) != NULL)
			i++;
		j = i;
		while (s[j] != '\0' && ft_strchr(delim, s[j]) == NULL)
			j++;
		res[index_res] = ft_substr(s, i, (j - i));
		if (res[index_res] == NULL)
		{
			ft_free_str_array(&res);
			return (NULL);
		}
		i = j + 1;
		index_res++;
	}
	return (res);
}

char	**ft_split(char const *s, char *delim)
{
	size_t	nb_words;
	char	**res;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, delim);
	res = (char **) ft_calloc(nb_words + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (ft_extract_words(s, delim, res, nb_words));
}
