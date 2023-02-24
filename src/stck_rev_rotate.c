/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:34:26 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/22 22:02:46 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*iter;
	t_stack	*prev;

	if (!a)
		return ;
	if (!(*a)->next)
		return ;
	iter = *a;
	while (iter->next != NULL)
	{
		prev = iter;
		iter = iter->next;
	}
	prev->next = NULL;
	iter->next = *a;
	*a = iter;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

void	silent_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
