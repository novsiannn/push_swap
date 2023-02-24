/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_rev_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:35 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/06 20:14:57 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_sort_two(t_stack **b)
{
	if ((*b)->val < (*b)->next->val)
		sb(b);
}

void	rev_sort_three(t_stack **b)
{
	t_stack	*stack_mid;
	int		top;
	int		mid;
	int		last;

	stack_mid = (*b)->next;
	top = (*b)->val;
	mid = stack_mid->val;
	last = stack_mid->next->val;
	if (top < mid && last < top)
		sb(b);
	else if (top < mid && mid < last)
	{
		sb(b);
		rrb(b);
	}
	else if (top < last && last < mid)
		rb(b);
	else if (mid < last && last < top)
	{
		sb(b);
		rb(b);
	}
	else if (mid < top && top < last)
		rrb(b);
}
