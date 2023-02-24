/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trns_bfr_mdn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:53:03 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/06 20:15:09 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	transfer_below_median(t_stack **a, t_stack **b, int median)
{
	int	size_stack;
	int	i;

	size_stack = get_stack_size(*a);
	i = 0;
	while (i < size_stack)
	{
		if ((*a)->val < median)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}
