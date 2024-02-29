/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 16:27:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Puts all the elements from data->stack_a into an allocated array
 *	The result array is saved into data->stack_a_array
 *	In case of error, false is returned, else true is returned
 */
bool	push_swap_stack_a_to_array(t_ps_data *data)
{
	t_list		*list;
	t_int_type	*res;
	size_t		i;
	size_t		size;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->list == NULL)
		return (false);
	if (data->stack_a_array != NULL)
	{
		free(data->stack_a_array);
		data->stack_a_array = NULL;
	}
	list = (data->stack_a)->list;
	size = (data->stack_a)->size;
	res = (t_int_type *) malloc(size * sizeof(t_int_type));
	if (res == NULL)
		return (false);
	i = 0;
	while (i < size && list != NULL)
	{
		res[i++] = *((int *)(list->content));
		list = list->next;
	}
	data->stack_a_array = res;
	return (true);
}

/*
 *	Modifies the data stack_a in order to "clean" it
 *	Takes the index of each integer in data->stack_a_array to replace
 *	the original value in data->stack_a
 *	Returns true on success, false in case of mistake
 */
bool	push_swap_clean_stack(t_ps_data *data)
{
	size_t		index;
	t_list		*current;
	t_int_type	*value_ptr;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->stack_b->size != 0 || data->stack_a_array == NULL
		|| data->stack_a->list == NULL
	)
		return (false);
	current = data->stack_a->list;
	while (current != NULL)
	{
		value_ptr = (t_int_type *)(current->content);
		index = -1;
		while (++index < data->stack_a->size)
			if ((data->stack_a_array)[index] == *value_ptr)
				break ;
		if (index >= data->stack_a->size)
			return (false);
		*value_ptr = (t_int_type) index;
		current = current->next;
	}
	return (true);
}
