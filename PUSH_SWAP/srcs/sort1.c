/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 16:52:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Pushes all the elements from stack A of data to stack B
 *	Takes the minimum of stack A at each iteration
 *	Stops when A contains three elements
 */
static void	all_mins_a_to_b(t_ps_data *data)
{
	t_stack	*a;
	size_t	min_index;

	if (data == NULL || data->stack_a == NULL)
		return ;
	a = data->stack_a;
	while (a->size > 3 && !(data->is_sorted_stack(data, STACK_A_LETTER)))
	{
		min_index = get_min_index(a);
		if (min_index <= a->size / 2)
			multiple_ra(data, min_index);
		else
			multiple_rra(data, a->size - min_index);
		if (!(data->is_sorted_stack(data, STACK_A_LETTER)))
			data->pb(data, true);
	}
	if (a->size == 3)
		sort_size_three(data);
}

/*
 *	Pushes all the element from stack B from data to stack A
 */
static void	all_b_to_a(t_ps_data *data)
{
	if (data == NULL || data->stack_b == NULL)
		return ;
	while ((data->stack_b)->size > 0)
		data->pa(data, true);
}

/*
 *	Sorts basically the stack A of given data.
 *	All the minimum values of A are put on top of B
 *	Then B is reverse sorted and all its values are pushed back to A
 */
void	sort1(t_ps_data *data)
{
	if (data == NULL || data->is_sorted_stack(data, STACK_A_LETTER))
		return ;
	all_mins_a_to_b(data);
	all_b_to_a(data);
	return ;
}
