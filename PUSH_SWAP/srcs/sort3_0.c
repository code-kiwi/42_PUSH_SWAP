/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:25:58 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 15:37:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Frist step of sort3 algorithm: makes a sorted array from stack_a and
 *	modifies the values from stack_a, replacing them by their index into the
 *	sorted array obtaines earlier
 */
static void	sort3_init(t_ps_data *data)
{
	if (data == NULL || !(data->stack_a_to_array(data)))
		sort_failure(data);
	sort_int_array(data->stack_a_array, data->stack_a->size);
	if (!(data->clean_stack(data)))
		sort_failure(data);
}

/*
 *	Sorts stack a of given data
 *	Uses the hourglass algorithm:
 *		-	the numbers from stack_a are sent into stack_b, resulting in
 *			an hourglass structure into stack_b (will minimize the cost
 *			of moving from stack_b to stack_a while sorting
 *		-	sends back the elements from stack_b to stack_a by sorting them
 *	In case of error, the program exits after having cleaned the memory
 */
void	sort3(t_ps_data *data)
{
	if (data == NULL)
		sort_failure(data);
	sort3_init(data);
	sort3_from_a_to_b(data);
	sort3_from_b_to_a(data);
}
