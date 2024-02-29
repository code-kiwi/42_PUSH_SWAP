# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 14:28:05 by mhotting          #+#    #+#              #
#    Updated: 2024/02/18 16:24:51 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME			=	libft.a
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

# HEADERS
HEADERS_DIR		=	includes/
HEADERS_FILES	=	libft.h fpf_buffer.h ft_printf.h get_next_line.h
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# STRING
STRING_DIR		=	string/
STRING_FILES	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c			\
					ft_isspace.c ft_isdigit.c ft_isprint.c ft_itoa.c			\
					ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c				\
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c			\
					ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c		\
					ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c			\
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c			\
					ft_toupper.c ft_ctoa.c ft_get_long_len.c ft_ltoa.c			\
					ft_ltoa_base.c ft_get_ulong_len.c ft_ultoa_base.c			\
					ft_is_valid_base.c ft_atol.c ft_atoul.c ft_prepend_chars.c	\
					ft_append_chars.c ft_strcmp.c ft_free_str_array.c			\
					ft_strtok.c ft_count_words.c
STRING			=	$(addprefix $(STRING_DIR), $(STRING_FILES))

# MEMORY
MEMORY_DIR		=	memory/
MEMORY_FILES	=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c	\
					ft_memmove.c ft_memset.c
MEMORY			=	$(addprefix $(MEMORY_DIR), $(MEMORY_FILES))

# LIST
LIST_DIR		=	list/
LIST_FILES		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c			\
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c		\
					ft_lstnew.c ft_lstsize.c ft_lstreverse.c
LIST			=	$(addprefix $(LIST_DIR), $(LIST_FILES))

# BUFFER
BUFFER_DIR		=	buffer/
BUFFER_FILES	=	fpf_buffer_utils1.c fpf_buffer_utils2.c
BUFFER			=	$(addprefix $(BUFFER_DIR), $(BUFFER_FILES))

# FT_PRINTF
FT_PRINTF_DIR	=	ft_printf/
FT_PRINTF_FILES	=	ft_printf.c ft_printf_utils.c input_format_utils.c			\
					format_dispatcher_utils.c fpf_formatter.c					\
					fpf_char_manager.c fpf_hexa_manager.c fpf_int_manager.c		\
					fpf_percent_manager.c fpf_ptr_manager.c						\
					fpf_string_manager.c fpf_uint_manager.c
FT_PRINTF		=	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))

# GET_NEXT_LINE
GNL_DIR			=	gnl/
GNL_FILES		=	get_next_line.c get_next_line_utils.c
GNL				=	$(addprefix $(GNL_DIR), $(GNL_FILES))

# SOURCES
SRCS_MAIN_DIR	=	srcs/
SRCS_FILES		=	$(STRING) $(MEMORY) $(LIST) $(BUFFER) $(FT_PRINTF) $(GNL)
SRCS			=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS
OBJS_MAIN_DIR	=	objs/
OBJS_FILES		=	$(SRCS_FILES:.c=.o)
OBJS			=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# DEPENDENCIES
DEPS_MAIN_DIR	=	deps/
DEPS_FILES		=	$(OBJS_FILES:.o=.d)
DEPS			=	$(addprefix $(DEPS_MAIN_DIR), $(DEPS_FILES))

#################################################

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c
	@mkdir -p $(@D)
	@mkdir -p $(DEPS_MAIN_DIR)$(dir $*)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -MP -MMD -MF $(DEPS_MAIN_DIR)$*.d -c $< -o $@ 

-include $(DEPS)

clean:
	rm -rf $(OBJS_MAIN_DIR)
	rm -rf $(DEPS_MAIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
