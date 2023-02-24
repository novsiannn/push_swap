/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:43:18 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/23 17:55:23 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	if (check_is_it_sorted(a))
		thr_error_silent(&a);
	b = NULL;
	sort_s(&a, &b, argc);
	sort_b(&a, &b);
	free_stack(&a);
}
