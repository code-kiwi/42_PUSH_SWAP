/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 16:27:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Allocates a t_ps_data and set its components values
 *	The stacks A and B are allocated too but empty
 *	NB:	- calls p_data_set_functions in order to initialize function pointers
 *		- if an allocated fails, NULL is returned
 */
t_ps_data	*ps_data_init(void)
{
	t_ps_data	*data;

	data = (t_ps_data *) malloc(sizeof(t_ps_data));
	if (data == NULL)
		return (NULL);
	data->stack_a = stack_init();
	if (data->stack_a == NULL)
	{
		free(data);
		return (NULL);
	}
	data->stack_b = stack_init();
	if (data->stack_b == NULL)
	{
		(data->stack_a)->clear(&(data->stack_a), free);
		free(data);
		return (NULL);
	}
	data->stack_a_array = NULL;
	ps_data_set_functions(data);
	return (data);
}

/*
 *	Sets the function pointers of the given t_ps_data pointer
 */
void	ps_data_set_functions(t_ps_data *data)
{
	if (data == NULL)
		return ;
	data->sa = push_swap_sa;
	data->sb = push_swap_sb;
	data->ss = push_swap_ss;
	data->pa = push_swap_pa;
	data->pb = push_swap_pb;
	data->ra = push_swap_ra;
	data->rb = push_swap_rb;
	data->rr = push_swap_rr;
	data->rra = push_swap_rra;
	data->rrb = push_swap_rrb;
	data->rrr = push_swap_rrr;
	data->push_a = push_swap_push_a;
	data->reverse_a = push_swap_reverse_a;
	data->found_dup_a = push_swap_found_duplicates_a;
	data->clear = ps_data_clear;
	data->handle_printf_error = push_swap_handle_printf_errors;
	data->is_sorted_stack = push_swap_is_sorted_stack;
	data->is_rev_sorted_stack = push_swap_is_rev_sorted_stack;
	data->stack_a_to_array = push_swap_stack_a_to_array;
	data->clean_stack = push_swap_clean_stack;
}

/*
 *	Clears the given ps_data by freeing its stacks and the data itself
 *	Sets the given pointer to NULL
 */
void	ps_data_clear(t_ps_data **data)
{
	t_stack	*stack;

	if (data == NULL || *data == NULL)
		return ;
	stack = (*data)->stack_a;
	stack->clear(&stack, free);
	stack = (*data)->stack_b;
	stack->clear(&stack, free);
	if ((*data)->stack_a_array != NULL)
		free((*data)->stack_a_array);
	free(*data);
	*data = NULL;
}

/*
 *	Handles the returned value as a printf returned value
 *	If (-1) is given, the program is left after having cleaned the memory
 *	Else nothing happens
 */
void	push_swap_handle_printf_errors(t_ps_data *data, int returned)
{
	if (returned == -1)
	{
		data->clear(&data);
		exit(EXIT_FAILURE);
	}
}
