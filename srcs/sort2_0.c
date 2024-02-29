/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/06 12:46:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Rotates stack b of data in order to put the greatest number at the top of
 *	of the stack
 *	Best solution is selected between rotating or reverse rotating
 */
static void	sort2_rotb(t_ps_data *data)
{
	size_t	max_index;
	size_t	size_b;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_rev_sorted_stack(data, STACK_B_LETTER)
		|| (data->stack_b)->size < 2
	)
		return ;
	max_index = get_max_index(data->stack_b);
	size_b = (data->stack_b)->size;
	if (max_index <= size_b / 2)
		multiple_rb(data, max_index);
	else
		multiple_rrb(data, (size_b - max_index));
}

/*
 *	Pushes each element from stack a of data to stack b
 *	Stack b's order is kept
 *	In order to minimize the number of moves, the less expansive move
 *	is calculated before moving an element from a to b)
 */
static void	sort2_a_to_b(t_ps_data *data)
{
	t_cost	min_cost;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	while ((data->stack_a)->size > 0)
	{
		sort2_calc_min_cost(data, &min_cost);
		sort2_a_to_b_move(data, &min_cost);
		data->pb(data, true);
	}
}

/*
 *	Pushes two elements from stack a of data into stack_b
 *	If b is not sorted, then sb is applied
 */
static void	sort2_init(t_ps_data *data)
{
	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
		|| (data->stack_a)->size < 2
	)
		return ;
	data->pb(data, true);
	data->pb(data, true);
	if (!(data->is_rev_sorted_stack(data, STACK_B_LETTER)))
		data->sb(data, true);
}

/*
 *	Sorts stack a of given data
 *	The algorithm works as follow:
 *		-	pushes two elements to b and sorts b if necessary;
 *		-	pushes each element of a to b by finding the lesse expansive move
 *			(parses a and calculates the number of move necessary to put
 *			each number into b, by keeping b reverse sorted)
 *		-	when a is empty, all elements from b are pushed back to a
 */
void	sort2(t_ps_data *data)
{
	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
		|| (data->stack_a)->size < 2
	)
		return ;
	sort2_init(data);
	sort2_a_to_b(data);
	sort2_rotb(data);
	while ((data->stack_b)->size > 0)
		data->pa(data, true);
}
