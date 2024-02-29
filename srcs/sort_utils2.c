/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 16:58:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Applies ra to data, nb times
 */
void	multiple_ra(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < nb)
	{
		data->ra(data, true);
		i++;
	}
}

/*
 *	Applies rra to data, nb times
 */
void	multiple_rra(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rra(data, true);
		i++;
	}
}

/*
 *	Applies rb to data, nb times
 */
void	multiple_rb(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rb(data, true);
		i++;
	}
}

/*
 *	Applies rrb to data, nb times
 */
void	multiple_rrb(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rrb(data, true);
		i++;
	}
}
