/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:37:30 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/23 18:48:51 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*a = tmp_a->next;
	*b = tmp_a;
	tmp_a->next = tmp_b;
	ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*b = tmp_b->next;
	*a = tmp_b;
	tmp_b->next = tmp_a;
	ft_printf("pa\n");
}

void	silent_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*b = tmp_b->next;
	*a = tmp_b;
	tmp_b->next = tmp_a;
}

void	silent_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*a = tmp_a->next;
	*b = tmp_a;
	tmp_a->next = tmp_b;
}
