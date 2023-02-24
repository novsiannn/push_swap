/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:21:20 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/23 17:59:27 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

void	sort_three(t_stack **a)
{
	t_stack	*middle_stack;
	int		third;
	int		first;
	int		second;

	middle_stack = (*a)->next;
	first = (*a)->val;
	second = middle_stack->val;
	third = middle_stack->next->val;
	if (first > second && third > first)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (third > second && first > third)
		ra(a);
	else if (second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && third < first)
		rra(a);
}

void	sort_four_to_six(t_stack **a, t_stack **b)
{
	int	median;
	int	count;
	int	a_size;
	int	b_size;

	count = 0;
	median = get_stack_mid_val(*a);
	transfer_below_median(a, b, median);
	a_size = get_stack_size(*a);
	b_size = get_stack_size(*b);
	if (a_size == 2)
		sort_two(a);
	else if (a_size == 3)
		sort_three(a);
	if (b_size == 2)
		rev_sort_two(b);
	else if (b_size == 3)
		rev_sort_three(b);
	while (count < b_size)
	{
		pa(a, b);
		count++;
	}
}

void	sort_s(t_stack **a, t_stack **b, int ac)
{
	if (ac == 3)
		sort_two(a);
	else if (ac == 4)
		sort_three(a);
	else if (ac <= 7 && ac >= 5)
		sort_four_to_six(a, b);
}
