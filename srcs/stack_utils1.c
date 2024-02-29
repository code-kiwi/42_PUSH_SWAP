/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:04:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 18:36:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
 *	Allocates a t_stack and sets its components values
 *	The chained list is set to NULL
 */
t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->list = NULL;
	stack->size = 0;
	stack->push_data = stack_push_data;
	stack->push_link = stack_push_link;
	stack->pop_data = stack_pop_data;
	stack->pop_link = stack_pop_link;
	stack->swap = stack_swap;
	stack->rotate = stack_rotate;
	stack->rev_rotate = stack_rev_rotate;
	stack->reverse = stack_reverse;
	stack->clear = stack_clear;
	return (stack);
}

/*
 *	Clears the given stack by freeing the list and its content
 *	Clears the stack given as input and set the given pointer to NULL
 *	NB:	- del parameter can be NULL, then the list is freed but the contents
 *		are not freed (useful if list content has not been allocated
 */
void	stack_clear(t_stack **stack, void (*del)(void *))
{
	if (stack == NULL || *stack == NULL)
		return ;
	ft_lstclear(&((*stack)->list), del);
	free(*stack);
	*stack = NULL;
}

/*
 *	Appends an element to the given t_stack (at the top of the stack)
 *	A new link is created using the data
 *	Returns true on success, else returns false
 */
bool	stack_push_data(t_stack *stack, void *data)
{
	t_list	*new;

	if (stack == NULL || data == NULL)
		return (false);
	new = ft_lstnew(data);
	if (new == NULL)
		return (false);
	ft_lstadd_front(&(stack->list), new);
	stack->size += 1;
	return (true);
}

/*
 *	Appends a link to the given t_stack (at the top of the stack)
 */
void	stack_push_link(t_stack *stack, t_list *new_link)
{
	if (stack == NULL || new_link == NULL)
		return ;
	ft_lstadd_front(&(stack->list), new_link);
	stack->size += 1;
}

/*
 *	Reverses the stack
 */
void	stack_reverse(t_stack *stack)
{
	if (stack == NULL || stack->list == NULL)
		return ;
	ft_lstreverse(&(stack->list));
}
