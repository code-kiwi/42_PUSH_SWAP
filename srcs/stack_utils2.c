/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:04:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 18:37:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
 *	Returns the first data of the given t_stack
 *	The returned element is removed from the t_stack
 *	In case of error, NULL is returned
 */
void	*stack_pop_data(t_stack *stack)
{
	t_list	*head;
	void	*data;

	if (stack == NULL || stack->list == NULL)
		return (NULL);
	head = stack->list;
	data = head->content;
	stack->list = head->next;
	free(head);
	stack->size -= 1;
	return (data);
}

/*
 *	Returns the first link of the given t_stack
 *	The returned element is removed from the t_stack
 *	In case of error, NULL is returned
 */
t_list	*stack_pop_link(t_stack *stack)
{
	t_list	*head;

	if (stack == NULL || stack->list == NULL)
		return (NULL);
	head = stack->list;
	stack->list = head->next;
	stack->size -= 1;
	return (head);
}

/*
 *	Swaps the first two elements of the given stack
 */
void	stack_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->list == NULL || (stack->list)->next == NULL)
		return ;
	first = stack->list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->list = second;
}

/*
 *	Rotation of the given t_stack:
 *		- the first element becomes the last
 *		- the other elements are moved up
 */
void	stack_rotate(t_stack *stack)
{
	t_list	*current;
	t_list	*head;

	if (stack == NULL || stack->list == NULL || (stack->list)->next == NULL)
		return ;
	head = stack->list;
	current = head->next;
	head->next = NULL;
	stack->list = current;
	while (current->next != NULL)
		current = current->next;
	current->next = head;
	return ;
}

/*
 *	Reverse rotation of the given t_stack:
 *		- the last element becomes the first
 *		- the other elements are moved down
 */
void	stack_rev_rotate(t_stack *stack)
{
	t_list	*current;
	t_list	*prev;

	if (stack == NULL || stack->list == NULL || (stack->list)->next == NULL)
		return ;
	prev = NULL;
	current = stack->list;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->list;
	stack->list = current;
}
