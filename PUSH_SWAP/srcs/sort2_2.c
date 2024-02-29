/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 10:24:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Returns the index of the first element lower than val_to_check inside of
 *	the given list
 *	Stops when idx_start has reached idx_end
 *	If no element is found, ids_start is returned
 */
static size_t	get_idx_of_elt(
		t_list *list, size_t idx_start, size_t idx_end, t_int_type val_to_check
)
{
	t_int_type	val_current;

	while (idx_start < idx_end && list != NULL)
	{
		val_current = *((t_int_type *)(list->content));
		if (val_to_check > val_current)
			return (idx_start);
		idx_start++;
		list = list->next;
	}
	return (idx_start);
}

/*
 *	Returns the list pointer at the given index
 */
static t_list	*get_list_element_at_index(t_list *list, size_t index)
{
	size_t	i;

	if (list == NULL)
		return (NULL);
	i = 0;
	while (i < index && list != NULL)
	{
		list = list->next;
		i++;
	}
	return (list);
}

/*
 *	Determines the index above which an element from stack a of data
 *	will be positionned in stack b
 */
size_t	sort2_get_index_in_b(t_ps_data *data, size_t index_in_a)
{
	t_list		*list;
	size_t		idx_b;
	size_t		idx_max_b;
	t_int_type	*val_a;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return (0);
	val_a = get_value_at_index(data->stack_a, index_in_a);
	if (val_a == NULL)
		sort_failure(data);
	idx_max_b = get_max_index(data->stack_b);
	idx_b = idx_max_b;
	list = get_list_element_at_index((data->stack_b)->list, idx_b);
	idx_b = get_idx_of_elt(list, idx_b, (data->stack_b)->size, *val_a);
	if (idx_b < (data->stack_b)->size)
		return (idx_b);
	idx_b = 0;
	list = (data->stack_b)->list;
	idx_b = get_idx_of_elt(list, idx_b, idx_max_b, *val_a);
	return (idx_b);
}
