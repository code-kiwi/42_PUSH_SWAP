/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:48:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/16 15:23:09 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Skips all the spaces of the given str
 *	The address of str is modified in order to correspond
 *	to the first non-space character
 *	NB: NOT A PURE FUNCTION, USE WITH CAUTIONS BECAUSE OF SIDE EFFECTS
 */
static void	skip_spaces(char **str)
{
	char	*nb;

	if (str == NULL)
		return ;
	nb = *str;
	while (ft_isspace(*nb))
		nb++;
	*str = nb;
}

/*
 *	Checks if the given string corresponds to an integer without overflowing
 *	integer limits (not less than INT_MIN or greater than INT_MAX
 *	Returns true if the integer is valid, false if it is not
 */
static bool	is_integer_not_overflow(char *str)
{
	long	nb;
	char	*end;
	char	*mem_str;

	if (str == NULL)
		return (false);
	mem_str = str;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (*str == '0')
		str++;
	end = str;
	while (*end != '\0' && ft_isdigit(*end))
		end++;
	if (end - str > 10)
		return (false);
	nb = ft_atol(mem_str);
	if (nb < (long) INT_MIN || nb > (long) INT_MAX)
		return (false);
	return (true);
}

/*
 *	Checks is the given str is a valid number
 *	A valid number can start or finish with an arbitrary amount of spaces
 *	A valid number can start with '-' or '+'
 *	Spaces are defined like in the isspace() function.
 */
static bool	is_valid_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	skip_spaces(&str);
	if (!is_integer_not_overflow(str))
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0' || !ft_isdigit(*str))
		return (false);
	while (*str && ft_isdigit(*str))
		str++;
	skip_spaces(&str);
	if (*str == '\0')
		return (true);
	return (false);
}

/*
 *	Parses the given string argv in order to put its numbers into data's stack_a
 *	The first number from argv will be the head of data's stack_a
 *	Returns true on success, false on error
 */
bool	parse_args(t_ps_data *data, int argc, char **argv)
{
	size_t	i;

	if (data == NULL || argv == NULL)
		return (false);
	i = argc - 1;
	while (true)
	{
		if (!is_valid_integer(argv[i]))
			return (false);
		if (!(data->push_a(data, ft_atoi(argv[i]))))
			return (false);
		if (i == 0)
			break ;
		i--;
	}
	return (true);
}

/*
 *	Parses the given string str in order to put its numbers into data's stack_a
 *	The first number from str will be the head of data's stack_a
 *	Returns true on success, false on error
 *	NB:	- numbers can be seperated by an arbitrary number of spaces
 *		- spaces are defined like in isspace() function
 */
bool	parse_one_arg(t_ps_data *data, char *str)
{
	char	*curr_nb_end;

	if (str == NULL || data == NULL)
		return (false);
	while (*str != '\0')
	{
		skip_spaces(&str);
		curr_nb_end = str;
		if (!is_integer_not_overflow(str))
			return (false);
		if (*curr_nb_end == '+' || *curr_nb_end == '-')
			curr_nb_end++;
		if (*curr_nb_end == '\0' || !ft_isdigit(*curr_nb_end))
			return (false);
		while (ft_isdigit(*curr_nb_end))
			curr_nb_end++;
		if ((*curr_nb_end != '\0' && !ft_isspace(*curr_nb_end)) \
			|| !(data->push_a(data, ft_atoi(str))))
			return (false);
		skip_spaces(&curr_nb_end);
		str = curr_nb_end;
	}
	data->reverse_a(data);
	return (true);
}
