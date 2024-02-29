/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 10:23:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Adds nb to the stack_a of the given data
 *	Allocates a pointer to an t_int_type
 *	This type is chosen because stack could contain sorted indexes of integers
 *	instead of integer values and -2147483648 to 2147483647 can lead to indexes
 *	greater than INT_MAX (indexes are positive numbers)
 *	Returns true on success, false on failure
 */
bool	push_swap_push_a(t_ps_data *data, int nb)
{
	t_stack		*stack_a;
	t_int_type	*nb_allocated;

	if (data == NULL || data->stack_a == NULL)
		return (false);
	nb_allocated = (t_int_type *) malloc(sizeof(t_int_type));
	if (nb_allocated == NULL)
		return (false);
	*nb_allocated = (t_int_type) nb;
	stack_a = data->stack_a;
	if (!(stack_a->push_data(stack_a, (void *) nb_allocated)))
	{
		free(nb_allocated);
		return (false);
	}
	return (true);
}

/*
 *	Reverses the content of stack_a of the given data
 */
void	push_swap_reverse_a(t_ps_data *data)
{
	if (data == NULL || data->stack_a == NULL)
		return ;
	(data->stack_a)->reverse(data->stack_a);
}

/*
 *	Checks for duplicate integers inside of stack_a member of given data
 *	Returns true if a duplicate is found, else returns false
 */
bool	push_swap_found_duplicates_a(t_ps_data *data)
{
	t_list		*curr;
	t_list		*next;
	t_int_type	curr_nb;
	t_int_type	next_nb;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->list == NULL)
		return (false);
	curr = (data->stack_a)->list;
	while (curr->next != NULL && curr->content != NULL)
	{
		curr_nb = *((t_int_type *)(curr->content));
		next = curr->next;
		while (next != NULL)
		{
			if (next->content == NULL)
				return (false);
			next_nb = *((t_int_type *)(next->content));
			if (curr_nb == next_nb)
				return (true);
			next = next->next;
		}
		curr = curr->next;
	}
	return (false);
}

/*
 *	Checks if the stack STACK_A_LETTER or STACK_B_LETTER from data is sorted
 *	Returns true if it is, else returns false
 *	If the stack is empty, returns true
 *	If there is an error (NULL pointer or bad stack_letter), returns false
 */
bool	push_swap_is_sorted_stack(t_ps_data *data, char letter)
{
	t_stack		*stack;
	t_list		*list;
	t_int_type	nb1;
	t_int_type	nb2;

	if (data == NULL || (letter != STACK_A_LETTER && letter != STACK_B_LETTER))
		return (false);
	if (letter == STACK_A_LETTER)
		stack = data->stack_a;
	else
		stack = data->stack_b;
	if (stack == NULL)
		return (false);
	list = stack->list;
	if (list == NULL)
		return (true);
	while (list->next != NULL)
	{
		nb1 = *((t_int_type *)list->content);
		nb2 = *((t_int_type *)(list->next)->content);
		if (nb1 > nb2)
			return (false);
		list = list->next;
	}
	return (true);
}

/*
 *	Checks if the stack STACK_A_LETTER or STACK_B_LETTER
 *	from data is reverse sorted
 *	Returns true if it is, else returns false
 *	If the stack is empty, returns true
 *	If there is an error (NULL pointer or bad stack_letter), returns false
 */
bool	push_swap_is_rev_sorted_stack(t_ps_data *data, char letter)
{
	t_stack		*stack;
	t_list		*list;
	t_int_type	nb1;
	t_int_type	nb2;

	if (data == NULL || (letter != STACK_A_LETTER && letter != STACK_B_LETTER))
		return (false);
	if (letter == STACK_A_LETTER)
		stack = data->stack_a;
	else
		stack = data->stack_b;
	if (stack == NULL)
		return (false);
	list = stack->list;
	if (list == NULL)
		return (true);
	while (list->next != NULL)
	{
		nb1 = *((t_int_type *)list->content);
		nb2 = *((t_int_type *)(list->next)->content);
		if (nb1 < nb2)
			return (false);
		list = list->next;
	}
	return (true);
}
