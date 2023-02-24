/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:13:22 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/24 11:46:13 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	read_operations(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "pa\n", 4))
		silent_pa(a, b);
	else if (!ft_strncmp(op, "pb\n", 4))
		silent_pb(a, b);
	else if (!ft_strncmp(op, "sa\n", 4))
		swap(a);
	else if (!ft_strncmp(op, "sb\n", 4))
		swap(b);
	else if (!ft_strncmp(op, "ss\n", 4))
		silent_ss(a, b);
	else if (!ft_strncmp(op, "ra\n", 4))
		rotate(a);
	else if (!ft_strncmp(op, "rb\n", 4))
		rotate(b);
	else if (!ft_strncmp(op, "rr\n", 4))
		silent_rr(a, b);
	else if (!ft_strncmp(op, "rra\n", 5))
		reverse_rotate(a);
	else if (!ft_strncmp(op, "rrb\n", 5))
		reverse_rotate(b);
	else if (!ft_strncmp(op, "rrr\n", 5))
		silent_rrr(a, b);
	else
		return (0);
	return (1);
}

void	show_result(t_stack *a, t_stack *b)
{
	if (check_is_it_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (ac < 2)
		return (0);
	b = NULL;
	a = init_stack_a(ac, av);
	if (check_is_it_sorted(a))
		thr_error_silent(&a);
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		if (!read_operations(&a, &b, op))
		{
			free(op);
			thr_error(&a);
		}
		free(op);
	}
	show_result(a, b);
	free_stack(&a);
	free_stack(&b);
}
