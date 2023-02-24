/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:02:43 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/21 14:39:51 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_closest_move(int ind, int size)
{
	if (ind <= size / 2)
		return (ind);
	else
		return (ind - size);
}

//Val it is number from stack b and *a is our a stack
int	get_position_in_a(int val, t_stack *a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*prev;
	int		size_a;
	int		stack_min;

	i = get_stack_max_elem(a);
	tmp = a->next;
	prev = a;
	size_a = get_stack_size(a);
	stack_min = get_stack_min_elem(a);
	if (val > i)
		return (get_closest_move(get_stack_val_index(a, i), size_a) + 1);
	if (val < stack_min)
		return (get_closest_move(get_stack_val_index(a, stack_min), size_a));
	i = 1;
	while (tmp)
	{
		if (tmp->val > val && val > prev->val)
			return (get_closest_move(i, size_a));
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	return (get_closest_move(i, size_a));
}

t_transf_price	*get_transf_price(t_stack *a, t_stack *b, int *tp_size)
{
	int				b_size;
	t_transf_price	*ret;
	int				i;
	t_stack			*tmp;

	b_size = get_stack_size(b);
	i = 0;
	tmp = b;
	ret = (t_transf_price *)malloc(sizeof(t_transf_price) * b_size);
	while (tmp)
	{
		ret[i].val = tmp->val;
		ret[i].move_count[0] = get_position_in_a(tmp->val, a);
		if (i <= b_size / 2)
			ret[i].move_count[1] = i;
		else
			ret[i].move_count[1] = i - b_size;
		i++;
		tmp = tmp->next;
	}
	*tp_size = b_size;
	return (ret);
}

int	pick_best_move_index(t_transf_price	*tp, int tp_size)
{
	int	i;
	int	cm;
	int	best_index;
	int	moves_best;

	i = 0;
	best_index = -1;
	moves_best = INT_MAX;
	cm = 0;
	while (i < tp_size)
	{
		if (tp[i].move_count[0] * tp[i].move_count[1] > 0)
			cm = max(abs(tp[i].move_count[0]), abs(tp[i].move_count[1]));
		else
			cm = abs(tp[i].move_count[0]) + abs(tp[i].move_count[1]);
		if (cm < moves_best)
		{
			best_index = i;
			moves_best = cm;
		}
		i++;
	}
	return (best_index);
}
