/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:57:22 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/23 18:50:58 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	execute_single_case(t_transf_price	*tpi, t_stack **a, t_stack **b)
{
	if (tpi->move_count[0] > 0)
	{
		ra(a);
		tpi->move_count[0] -= 1;
	}
	if (tpi->move_count[0] < 0)
	{
		rra(a);
		tpi->move_count[0] += 1;
	}
	if (tpi->move_count[1] > 0)
	{
		rb(b);
		tpi->move_count[1] -= 1;
	}
	if (tpi->move_count[1] < 0)
	{
		rrb(b);
		tpi->move_count[1] += 1;
	}
}

void	exec_op_move(t_transf_price	tpi, t_stack **a, t_stack **b)
{
	while (tpi.move_count[0] != 0 || tpi.move_count[1] != 0)
	{
		if (tpi.move_count[0] > 0 && tpi.move_count[1] > 0)
		{
			rr(a, b);
			tpi.move_count[0] -= 1;
			tpi.move_count[1] -= 1;
		}
		else if (tpi.move_count[0] > 0 && tpi.move_count[1] > 0)
		{
			rrr(a, b);
			tpi.move_count[0] += 1;
			tpi.move_count[1] += 1;
		}
		else
			execute_single_case(&tpi, a, b);
	}
	pa(a, b);
}

void	sort_b(t_stack **a, t_stack **b)
{
	int				tp_size;
	int				tp_index;
	int				a_size;
	t_transf_price	*tp;

	if (check_is_it_sorted(*a))
		return ;
	move_to_lis_b(a, b);
	while (*b)
	{
		tp = get_transf_price(*a, *b, &tp_size);
		tp_index = pick_best_move_index(tp, tp_size);
		exec_op_move(tp[tp_index], a, b);
		free(tp);
	}
	a_size = get_stack_size(*a);
	if (get_stack_val_index(*a, (get_stack_max_elem(*a))) <= a_size / 2)
		while (get_stack_val_index(*a, (get_stack_max_elem(*a))) != a_size - 1)
			ra(a);
	else
		while (get_stack_val_index(*a, (get_stack_max_elem(*a))) != a_size - 1)
			rra(a);
}

void	thr_error_silent(t_stack **a)
{
	free_stack(a);
	exit (0);
}
