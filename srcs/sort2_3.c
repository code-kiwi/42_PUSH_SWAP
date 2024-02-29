/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 17:16:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Applies a combination of ra, rb and rr according to min_cost data
 */
static void	sort2_rot_a_and_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	ra;
	size_t	rb;
	size_t	rr;

	if (data == NULL || min_cost == NULL)
		return ;
	ra = min_cost->idx_a;
	rb = min_cost->idx_b;
	rr = min_size_t(ra, rb);
	ra -= rr;
	rb -= rr;
	multiple_rr(data, rr);
	multiple_ra(data, ra);
	multiple_rb(data, rb);
}

/*
 *	Applies a combination of ra and rrb according to min_cost data
 */
static void	sort2_rot_a_rrot_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	ra;
	size_t	rrb;

	if (data == NULL || min_cost == NULL || data->stack_b == NULL)
		return ;
	ra = min_cost->idx_a;
	rrb = (data->stack_b)->size - (min_cost->idx_b);
	multiple_ra(data, ra);
	multiple_rrb(data, rrb);
}

/*
 *	Applies a combination of rra and rb according to min_cost data
 */
static void	sort2_rrot_a_rot_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	rra;
	size_t	rb;

	if (data == NULL || min_cost == NULL || data->stack_a == NULL)
		return ;
	rra = (data->stack_a)->size - (min_cost->idx_a);
	rb = min_cost->idx_b;
	multiple_rra(data, rra);
	multiple_rb(data, rb);
}

/*
 *	Applies a combination of rra, rrb and rrr according to min_cost data
 */
static void	sort2_rrot_a_and_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	rra;
	size_t	rrb;
	size_t	rrr;

	if (
		data == NULL || min_cost == NULL
		|| data->stack_a == NULL || data->stack_b == NULL
	)
		return ;
	rra = (data->stack_a)->size - (min_cost->idx_a);
	rrb = (data->stack_b)->size - (min_cost->idx_b);
	rrr = min_size_t(rra, rrb);
	rra -= rrr;
	rrb -= rrr;
	multiple_rrr(data, rrr);
	multiple_rra(data, rra);
	multiple_rrb(data, rrb);
}

/*
 *	Applies the moves necessary to move the element from stack a of data
 *	into stack b, according to data registered in min_cost
 */
void	sort2_a_to_b_move(t_ps_data *data, t_cost *min_cost)
{
	if (
		data == NULL || min_cost == NULL
		|| min_cost->type == COST_TYPE_UNDEFINED
	)
		return ;
	if (min_cost->type == COST_TYPE_ROT_A_AND_B)
		sort2_rot_a_and_b(data, min_cost);
	else if (min_cost->type == COST_TYPE_ROT_A_RROT_B)
		sort2_rot_a_rrot_b(data, min_cost);
	else if (min_cost->type == COST_TYPE_RROT_A_ROT_B)
		sort2_rrot_a_rot_b(data, min_cost);
	else if (min_cost->type == COST_TYPE_RROT_A_AND_B)
		sort2_rrot_a_and_b(data, min_cost);
}
