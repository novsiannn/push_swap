/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:27:31 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/23 18:50:19 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	if (!(*a)->next)
		return ;
	tmp = (*a)->next;
	if (!tmp)
		return ;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	sa(t_stack **a)
{
	swap (a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap (b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap (a);
	swap (b);
	ft_printf("ss\n");
}

void	silent_ss(t_stack **a, t_stack **b)
{
	swap (a);
	swap (b);
}
