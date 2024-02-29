/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:58:14 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/06 08:52:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Puts all the values of new_cost into old_cost
 */
void	set_cost(t_cost *old_cost, t_cost *new_cost)
{
	if (old_cost == NULL || new_cost == NULL)
		return ;
	old_cost->idx_a = new_cost->idx_a;
	old_cost->idx_b = new_cost->idx_b;
	old_cost->value = new_cost->value;
	old_cost->type = new_cost->type;
}
