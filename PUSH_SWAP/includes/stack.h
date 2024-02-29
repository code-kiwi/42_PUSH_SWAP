/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:41:14 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 18:35:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack
{
	t_list	*list;
	size_t	size;
	bool	(*push_data)(struct s_stack * stack, void *data);
	void	(*push_link)(struct s_stack *stack, t_list *new_link);
	void	*(*pop_data)(struct s_stack *stack);
	t_list	*(*pop_link)(struct s_stack *stack);
	void	(*swap)(struct s_stack *stack);
	void	(*rotate)(struct s_stack *stack);
	void	(*rev_rotate)(struct s_stack *stack);
	void	(*reverse)(struct s_stack *stack);
	void	(*clear)(struct s_stack **stack, void (*del)(void *));
}	t_stack;

t_stack	*stack_init(void);
bool	stack_push_data(t_stack *stack, void *data);
void	stack_push_link(t_stack *stack, t_list *new_link);
void	*stack_pop_data(t_stack *stack);
t_list	*stack_pop_link(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);
void	stack_reverse(t_stack *stack);
void	stack_clear(t_stack **stack, void (*del)(void *));

#endif
