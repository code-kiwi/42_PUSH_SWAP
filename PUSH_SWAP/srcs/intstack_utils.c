/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intstack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:53:56 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 10:23:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Returns the index of the minimum element of the given stack
 *	In case of error, 0 is returned
 */
size_t	get_min_index(t_stack *stack)
{
	t_int_type	min;
	t_int_type	current_value;
	size_t		min_index;
	size_t		current_index;
	t_list		*current;

	if (stack == NULL || stack->list == NULL)
		return (0);
	current = stack->list;
	min = *((t_int_type *) current->content);
	min_index = 0;
	current = current->next;
	current_index = 1;
	while (current != NULL)
	{
		current_value = *((t_int_type *) current->content);
		if (current_value < min)
		{
			min = current_value;
			min_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (min_index);
}

/*
 *	Returns the index of the maximum element of the given stack
 *	In case of error, 0 is returned
 */
size_t	get_max_index(t_stack *stack)
{
	t_int_type	max;
	t_int_type	current_value;
	size_t		max_index;
	size_t		current_index;
	t_list		*current;

	if (stack == NULL || stack->list == NULL)
		return (0);
	current = stack->list;
	max = *((t_int_type *) current->content);
	max_index = 0;
	current = current->next;
	current_index = 1;
	while (current != NULL)
	{
		current_value = *((t_int_type *) current->content);
		if (current_value > max)
		{
			max = current_value;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (max_index);
}

/*
 *	Returns the pointer to value of the element at the given index
 *	from the given stack
 *	In case of error, or if the index is not a part of the stack
 *	NULL is returned
 */
t_int_type	*get_value_at_index(t_stack *stack, size_t index)
{
	t_list	*list;
	size_t	curr_index;

	if (stack == NULL || stack->list == NULL)
		return (NULL);
	list = stack->list;
	curr_index = 0;
	while (curr_index < index && list != NULL)
	{
		list = list->next;
		curr_index++;
	}
	if (list == NULL)
		return (NULL);
	return ((t_int_type *)(list->content));
}
