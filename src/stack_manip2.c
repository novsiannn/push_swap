/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:16 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/23 18:52:54 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_stack_max_elem(t_stack *stack)
{
	int		num;
	t_stack	*tmp;

	tmp = stack;
	num = tmp->val;
	while (tmp != NULL)
	{
		if (num < tmp->val)
			num = tmp->val;
		tmp = tmp->next;
	}
	return (num);
}

int	get_stack_min_elem(t_stack *a)
{
	t_stack	*tmp;
	int		num;

	tmp = a;
	num = tmp->val;
	while (tmp != NULL)
	{
		if (tmp->val < num)
			num = tmp->val;
		tmp = tmp->next;
	}
	return (num);
}

void	put_min_elem_on_top(t_stack **stack)
{
	int	min_elem;
	int	ind;
	int	stack_size;
	int	i;

	min_elem = get_stack_min_elem(*stack);
	ind = get_stack_val_index(*stack, min_elem);
	stack_size = get_stack_size(*stack);
	i = 0;
	if (ind > stack_size / 2)
	{
		while (i < stack_size - ind)
		{
			reverse_rotate(stack);
			i++;
		}
	}
	else
	{
		while (i < ind)
		{
			rotate(stack);
			i++;
		}
	}
}

void	ft_free_strings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}
