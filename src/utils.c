/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:47:42 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/23 19:18:54 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// First elem of arr it's size of stack
int	*stack_to_arr(t_stack *stack)
{
	int		stack_size;
	int		*arr;
	int		i;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	stack_size = get_stack_size(stack);
	arr = (int *)malloc(sizeof(int) * (stack_size + 1));
	if (!arr)
		return (NULL);
	tmp = stack;
	i = 1;
	arr[0] = stack_size;
	while (tmp != NULL)
	{
		arr[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

int	get_stack_val_index(t_stack *stack, int val)
{
	t_stack	*tmp;
	int		ind;

	if (!stack)
		return (-1);
	tmp = stack;
	ind = 0;
	while (tmp != NULL)
	{
		if (tmp->val == val)
			break ;
		tmp = tmp->next;
		ind++;
	}
	return (ind);
}

int	get_stack_mid_val(t_stack *stack)
{
	int	result;
	int	*arr;
	int	arr_size;

	arr = stack_to_arr(stack);
	arr_size = arr[0];
	ft_bubble_sort(&arr[1], arr[0]);
	result = arr[arr_size / 2 + 1];
	free(arr);
	return (result);
}

void	free_double_pointer(void **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
