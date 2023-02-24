/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:17:38 by nikitos           #+#    #+#             */
/*   Updated: 2023/02/24 11:58:34 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_atoi_long(const char *str)
{
	long		convert;
	int			i;
	int			sign;

	convert = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		convert = (convert * 10) + (str[i] - '0');
		i++;
	}
	return (convert * sign);
}

void	bracket_parse(t_stack **a, char *argv)
{
	char		**new_arr;
	long		num;
	int			i;

	new_arr = ft_split(argv, ' ');
	if (new_arr[0] == NULL)
	{
		ft_free_strings(new_arr);
		thr_error(a);
	}
	i = 0;
	while (new_arr[i])
	{
		num = ft_atoi_long(new_arr[i]);
		if (num > 2147483647 || num < -2147483648)
			thr_error(a);
		add_to_stack(a, (int)num);
		i++;
	}
	reverse_stack(a);
	free_double_pointer((void **)new_arr, i);
}

void	normal_parse(t_stack **a, char **argv, int argc)
{
	long	num;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		num = ft_atoi_long(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			thr_error(a);
		add_to_stack(a, (int)num);
		i--;
	}
}

void	check_double_quotes(t_stack **a, char **argv)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j++])
		{
			if (j > 1)
			{
				ft_free_strings(tmp);
				thr_error(a);
			}
		}
		ft_free_strings(tmp);
	}
}

// In that function we initialize our stack :D
t_stack	*init_stack_a(int argc, char **argv)
{
	t_stack		*a;

	if (argc == 2 && argv[1][0] == 0)
		thr_error_silent(&a);
	if (!(check_int(argc, argv)) || argc < 2)
	{
		ft_putstr_fd("Error\n", 2);	
		exit (0);
	}
	a = NULL;
	if (argc == 2)
		bracket_parse(&a, argv[1]);
	else
	{
		check_double_quotes(&a, argv);
		normal_parse(&a, argv, argc);
	}
	if (check_dup_stack(a))
		thr_error(&a);
	return (a);
}
