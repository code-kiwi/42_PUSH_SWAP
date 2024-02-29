/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/09 20:47:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include "libft.h"
# include "stack.h"

# define SA_INSTRUCTION "sa\n"
# define SB_INSTRUCTION "sb\n"
# define SS_INSTRUCTION "ss\n"
# define PA_INSTRUCTION "pa\n"
# define PB_INSTRUCTION "pb\n"
# define RA_INSTRUCTION "ra\n"
# define RB_INSTRUCTION "rb\n"
# define RR_INSTRUCTION "rr\n"
# define RRA_INSTRUCTION "rra\n"
# define RRB_INSTRUCTION "rrb\n"
# define RRR_INSTRUCTION "rrr\n"
# define ERROR_MESSAGE "Error\n"
# define OK_MESSAGE "OK\n"
# define KO_MESSAGE "KO\n"
# define STACK_A_LETTER 'a'
# define STACK_B_LETTER 'b'
# define COST_TYPE_UNDEFINED 0
# define COST_TYPE_ROT_A_AND_B 1
# define COST_TYPE_ROT_A_RROT_B 2
# define COST_TYPE_RROT_A_ROT_B 3
# define COST_TYPE_RROT_A_AND_B 4

typedef int64_t	t_int_type;

typedef struct s_cost
{
	size_t			idx_a;
	size_t			idx_b;
	size_t			value;
	unsigned int	type;
}	t_cost;

typedef struct s_ps_data
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_int_type	*stack_a_array;
	void		(*sa)(struct s_ps_data *data, bool display);
	void		(*sb)(struct s_ps_data *data, bool display);
	void		(*ss)(struct s_ps_data *data, bool display);
	void		(*pa)(struct s_ps_data *data, bool display);
	void		(*pb)(struct s_ps_data *data, bool display);
	void		(*ra)(struct s_ps_data *data, bool display);
	void		(*rb)(struct s_ps_data *data, bool display);
	void		(*rr)(struct s_ps_data *data, bool display);
	void		(*rra)(struct s_ps_data *data, bool display);
	void		(*rrb)(struct s_ps_data *data, bool display);
	void		(*rrr)(struct s_ps_data *data, bool display);
	bool		(*push_a)(struct s_ps_data * data, int nb);
	void		(*reverse_a)(struct s_ps_data *data);
	bool		(*found_dup_a)(struct s_ps_data * data);
	void		(*clear)(struct s_ps_data **data);
	void		(*handle_printf_error)(struct s_ps_data *data, int returned);
	bool		(*is_sorted_stack)(struct s_ps_data * data, char stack_letter);
	bool		(*is_rev_sorted_stack)(\
			struct s_ps_data * data, char stack_letter);
	bool		(*stack_a_to_array)(struct s_ps_data * data);
	bool		(*clean_stack)(struct s_ps_data * data);
}	t_ps_data;

t_ps_data	*ps_data_init(void);
void		ps_data_set_functions(t_ps_data *data);
void		ps_data_clear(t_ps_data **data);
bool		push_swap_push_a(t_ps_data *data, int nb);
void		push_swap_reverse_a(t_ps_data *data);
bool		push_swap_is_sorted_stack(t_ps_data *data, char stack_letter);
bool		push_swap_is_rev_sorted_stack(t_ps_data *data, char stack_letter);
bool		push_swap_found_duplicates_a(t_ps_data *data);
void		push_swap_sa(t_ps_data *data, bool display);
void		push_swap_sb(t_ps_data *data, bool display);
void		push_swap_ss(t_ps_data *data, bool display);
void		push_swap_pa(t_ps_data *data, bool display);
void		push_swap_pb(t_ps_data *data, bool display);
void		push_swap_ra(t_ps_data *data, bool display);
void		push_swap_rb(t_ps_data *data, bool display);
void		push_swap_rr(t_ps_data *data, bool display);
void		push_swap_rra(t_ps_data *data, bool display);
void		push_swap_rrb(t_ps_data *data, bool display);
void		push_swap_rrr(t_ps_data *data, bool display);
void		push_swap_handle_printf_errors(t_ps_data *data, int returned);
bool		push_swap_stack_a_to_array(t_ps_data *data);
bool		push_swap_clean_stack(t_ps_data *data);

bool		parse_args(t_ps_data *data, int argc, char **argv);
bool		parse_one_arg(t_ps_data *data, char *str);

size_t		get_min_index(t_stack *stack);
size_t		get_max_index(t_stack *stack);
t_int_type	*get_value_at_index(t_stack *stack, size_t index);
void		sort_size_three(t_ps_data *data);
size_t		min_size_t(size_t n1, size_t n2);
void		sort_int_array(t_int_type *array, size_t size);
void		sort_failure(t_ps_data *data);

void		sort1(t_ps_data *data);
void		sort2(t_ps_data *data);
void		sort2_calc_min_cost(t_ps_data *data, t_cost *min_cost);
size_t		sort2_get_index_in_b(t_ps_data *data, size_t index_in_a);
void		sort2_a_to_b_move(t_ps_data *data, t_cost *min_cost);
void		sort3(t_ps_data *data);
void		sort3_from_a_to_b(t_ps_data *data);
void		sort3_from_b_to_a(t_ps_data *data);

void		multiple_ra(t_ps_data *data, size_t nb);
void		multiple_rra(t_ps_data *data, size_t nb);
void		multiple_rb(t_ps_data *data, size_t nb);
void		multiple_rrb(t_ps_data *data, size_t nb);
void		multiple_rr(t_ps_data *data, size_t nb);
void		multiple_rrr(t_ps_data *data, size_t nb);

void		set_cost(t_cost *old_cost, t_cost *new_cost);

#endif
