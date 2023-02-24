/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:04:25 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/23 18:50:44 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_stack(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new;

	new = new_stack(value);
	new->next = *stack;
	*stack = new;
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = *stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stack = prev;
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*dst;
	t_stack	*tmp;

	dst = NULL;
	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp != NULL)
	{
		add_to_stack(&dst, tmp->val);
		tmp = tmp->next;
	}
	reverse_stack(&dst);
	return (dst);
}

void	thr_error(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
