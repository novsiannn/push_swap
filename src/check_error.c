/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:32:54 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/24 12:42:57 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
				return (0);
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != ' ')
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_is_it_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->val > tmp->next->val)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_dup_sub(t_stack *stack, int val)
{
	t_stack	*tmp;
	int		dup_count;

	tmp = stack;
	dup_count = 0;
	while (tmp != NULL)
	{
		if (val == tmp->val)
			dup_count++;
		if (dup_count == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_dup_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (check_dup_sub(stack, tmp->val))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp_next;

	if (!a)
		return ;
	temp = *a;
	while (temp)
	{
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
	*a = NULL;
}
