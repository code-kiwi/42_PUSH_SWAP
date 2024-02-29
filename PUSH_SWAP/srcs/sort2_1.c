/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 17:10:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Determines the cost for moving an element, depending on the combination of
 *	moves necesary
 */
static size_t	calc_cost_value(size_t ra, size_t rb, size_t rra, size_t rrb)
{
	size_t	value;

	value = ra + rb - min_size_t(ra, rb);
	value = min_size_t(value, (ra + rrb));
	value = min_size_t(value, (rra + rb));
	value = min_size_t(value, (rra + rrb - min_size_t(rra, rrb)));
	return (value);
}

/*
 *	Determines if the move is:
 *		-	a combination of ra, rb and rr;
 *		-	a combination of ra and rrb;
 *		-	a combination of rra and rb;
 *		-	a combination of rra, rrb and rrr;
 */
static unsigned int	get_cost_type(size_t ra, size_t rb, size_t rra, size_t rrb)
{
	unsigned int	type;
	size_t			value;

	value = ra + rb - min_size_t(ra, rb);
	type = COST_TYPE_ROT_A_AND_B;
	if ((ra + rrb) < value)
	{
		value = ra + rrb;
		type = COST_TYPE_ROT_A_RROT_B;
	}
	if ((rra + rb) < value)
	{
		value = rra + rb;
		type = COST_TYPE_RROT_A_ROT_B;
	}
	if ((rra + rrb - min_size_t(rra, rrb)) < value)
	{
		value = rra + rrb - min_size_t(rra, rrb);
		type = COST_TYPE_RROT_A_AND_B;
	}
	return (type);
}

/*
 *	Evaluates the cost of a specific move in order to put an element from
 *	stack a of data to stack b
 */
static void	sort2_eval_cost(t_ps_data *data, t_cost *cost)
{
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;

	if (data == NULL || cost == NULL)
		return ;
	ra = cost->idx_a;
	rra = (data->stack_a)->size - cost->idx_a;
	rb = cost->idx_b;
	rrb = (data->stack_b)->size - cost->idx_b;
	cost->value = calc_cost_value(ra, rb, rra, rrb);
	cost->type = get_cost_type(ra, rb, rra, rrb);
}

/*
 *	Evaluates which element from stack a of data is the less expansive to
 *	move to stack b
 *	Then, its information are registered into min_cost
 */
void	sort2_calc_min_cost(t_ps_data *data, t_cost *min_cost)
{
	t_cost	cost;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| min_cost == NULL
	)
		return ;
	min_cost->idx_a = 0;
	min_cost->idx_b = sort2_get_index_in_b(data, min_cost->idx_a);
	min_cost->value = 0;
	min_cost->type = COST_TYPE_UNDEFINED;
	sort2_eval_cost(data, min_cost);
	cost.idx_a = 1;
	while (cost.idx_a < (data->stack_a)->size)
	{
		cost.idx_b = sort2_get_index_in_b(data, cost.idx_a);
		cost.value = 0;
		cost.type = COST_TYPE_UNDEFINED;
		sort2_eval_cost(data, &cost);
		if (cost.value < min_cost->value)
			set_cost(min_cost, &cost);
		cost.idx_a += 1;
	}
}
