/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:01:10 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/21 14:38:56 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (n * (-1));
}
