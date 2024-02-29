/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:17 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/23 10:32:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*current;

	if (lst == NULL)
		return ;
	if (new_node == NULL)
		return ;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		current = ft_lstlast(*lst);
		current->next = new_node;
	}
}
