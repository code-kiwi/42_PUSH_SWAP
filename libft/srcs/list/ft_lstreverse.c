/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:43:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/11 18:11:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*before;
	t_list	*curr;
	t_list	*next;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	before = NULL;
	curr = *lst;
	next = curr->next;
	while (curr != NULL)
	{
		curr->next = before;
		before = curr;
		curr = next;
		if (next != NULL)
			next = next->next;
	}
	*lst = before;
}
