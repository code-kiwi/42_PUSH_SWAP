/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:29:33 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/18 16:24:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

int				ft_atoi(const char *nptr);
long			ft_atol(const char *nb_ptr);
unsigned long	ft_atoul(const char *nb_ptr);
char			*ft_ctoa(int c);
void			ft_free_str_array(char ***res);
size_t			ft_get_long_len(long num, size_t base_len);
size_t			ft_get_ulong_len(unsigned long nb, size_t base_len);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
bool			ft_is_valid_base(char *base);
char			*ft_itoa(int n);
char			*ft_ltoa(long nb);
char			*ft_ltoa_base(long nb, char *base);
char			*ft_ultoa_base(unsigned long nb, char *base);
char			*ft_append_chars(char *str, char c, size_t len_total);
char			*ft_prepend_chars(char *str, char c, size_t len_total);
ssize_t			ft_putchar_fd(char c, int fd);
ssize_t			ft_putendl_fd(char *s, int fd);
ssize_t			ft_putnbr_fd(int n, int fd);
ssize_t			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char *delim);
char			*ft_strchr(const char *s, int c);
size_t			ft_count_words(const char *s, char *delim);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtok(char *str, const char *delim);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_lstadd_back(t_list **lst, t_list *new_node);
void			ft_lstadd_front(t_list **lst, t_list *new_node);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(
					t_list *lst, void *(*f)(void *),
					void (*del)(void *)
					);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstreverse(t_list **lst);

#endif
