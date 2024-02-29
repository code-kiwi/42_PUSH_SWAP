/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:25:58 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 15:43:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Returns the optimal chunck size according to the given stack size
 *	This value is obtained through a quadratic equation
 */
static t_int_type	get_chunk_size(size_t size)
{
	return ((t_int_type)(0.000000053 * (size * size) + 0.03 * size + 14.5));
}

/*
 *	Moves the elements from stack_a to stack_b
 *	Moves them step by step, starting with the closest from the
 *	smallest value to the furthest
 *	Rotates b in order to obtain an hourglass structure
 */
static void	sort3_process_a_to_b(t_ps_data *data, t_int_type chunk_size)
{
	t_int_type	*value;
	t_int_type	smallest;

	smallest = 0;
	while (data->stack_a->size > 0)
	{
		value = get_value_at_index(data->stack_a, 0);
		if (value == NULL)
			sort_failure(data);
		if (*value <= smallest)
		{
			data->pb(data, true);
			smallest++;
		}
		else if (*value > smallest && *value <= smallest + chunk_size)
		{
			data->pb(data, true);
			data->rb(data, true);
			smallest++;
		}
		else
			data->ra(data, true);
	}
}

/*
 *	Moves all elements from data stack_a to stack_b
 *	Moves it chunks by chunks in order to create an hourglass shape in stack_b
 */
void	sort3_from_a_to_b(t_ps_data *data)
{
	t_int_type	chunk_size;

	if (data == NULL || data->stack_a == NULL)
		return ;
	chunk_size = get_chunk_size(data->stack_a->size);
	sort3_process_a_to_b(data, chunk_size);
}

/*
 *	Moves all elements from data stack_b to stack_a
 *	Loops through stack_b and takes the maximum at each iteration
 *	in order to push it to stack_a
 */
void	sort3_from_b_to_a(t_ps_data *data)
{
	size_t	b_max_index;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	while (data->stack_b->size > 0)
	{
		b_max_index = get_max_index(data->stack_b);
		if (b_max_index <= data->stack_b->size / 2)
			multiple_rb(data, b_max_index);
		else
			multiple_rrb(data, data->stack_b->size - b_max_index);
		data->pa(data, true);
	}
}
