/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:03:35 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/23 19:19:17 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "../libftPrintf/inc/ft_printf.h"

// structures
typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

typedef struct s_transf_price
{
	int	move_count[2];
	int	val;
}t_transf_price;

// init functions
t_stack			*init_stack_a(int argc, char **argv);
t_stack			*copy_stack(t_stack *stack);

t_transf_price	*get_transf_price(t_stack *a, t_stack *b, int *tp_size);

// stack functions
int				get_stack_mid_val(t_stack *a);
int				get_stack_size(t_stack *stack);
int				*stack_to_arr(t_stack *stack);

void			transfer_below_median(t_stack **a, t_stack **b, int median);

// check functions
int				check_int(int argc, char **argv);
int				check_dup_sub(t_stack *stack, int val);
int				check_dup_stack(t_stack *stack);
int				check_is_it_sorted(t_stack *stack);
void			check_double_quotes(t_stack **a, char **argv);

//stack functions
int				get_stack_max_elem(t_stack *stack);
int				get_stack_min_elem(t_stack *a);
int				get_stack_val_index(t_stack *stack, int val);

void			add_to_stack(t_stack **stack, int value);
void			reverse_stack(t_stack **stack);
void			reverse_rotate(t_stack **a);
void			rotate(t_stack **a);
void			free_stack(t_stack **a);

// sort functions
void			sort_s(t_stack **a, t_stack **b, int ac);
void			sort_four_to_six(t_stack **a, t_stack **b);
void			rev_sort_two(t_stack **b);
void			rev_sort_three(t_stack **b);
void			ft_bubble_sort(int *arr, int size);

// reverse rotate functions
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			silent_rrr(t_stack **a, t_stack **b);

// reverse functions
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			silent_rr(t_stack **a, t_stack **b);

// push functions
void			pb(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			silent_pb(t_stack **a, t_stack **b);
void			silent_pa(t_stack **a, t_stack **b);

// switch functions
void			swap(t_stack **a);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			silent_ss(t_stack **a, t_stack **b);
// big sort
void			sort_b(t_stack **a, t_stack **b);

// largest increasing sequence (LIS)
void			put_min_elem_on_top(t_stack **stack);
int				get_stack_val_index(t_stack *stack, int val);
void			move_to_lis_b(t_stack **a, t_stack **b);
int				*get_lis(int *arr, int size, int *lis_size, int i);

// transfer functions
int				get_closest_move(int ind, int size);
int				pick_best_move_index(t_transf_price	*tp, int tp_size);

// math operations
int				min(int a, int b);
int				max(int a, int b);
int				abs(int n);

// error throw
void			thr_error(t_stack **a);
void			thr_error_silent(t_stack **a);
void			free_double_pointer(void **ptr, int size);
void			ft_free_strings(char **str);

#endif