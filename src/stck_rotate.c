/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:05:35 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/22 21:59:41 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (!a)
		return ;
	if (!(*a)->next)
		return ;
	tmp = *a;
	iter = *a;
	*a = tmp->next;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	silent_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
