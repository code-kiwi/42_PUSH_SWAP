/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:57 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/09 16:34:01 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "libft.h"

typedef struct s_list	t_list;

typedef struct s_buffer_save
{
	int		fd;
	char	*buffer;
}	t_buffer_save;

int		gnl_join(char **s1, char *s2, size_t s2_len);
void	*gnl_clean_memory(t_list **store, char *buffer, char *res);
char	*get_next_line(int fd);

#endif
