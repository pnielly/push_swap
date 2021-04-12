/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:09:08 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 23:12:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *str, char *pb)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(pb, 1);
	ft_putchar('\n');
	return (1);
}

/*
** Checks for errors in the original input from the user
*/

int	ft_check_for_error(int ac, char **av)
{
	if (ac == 1)
		return (1);
	while (--ac)
	{
		if (!ft_isnum(av[ac]))
			return (ft_error("Wrong input ! Only digits allowed : ", av[ac]));
		if (ft_atoi_long((const char *)av[ac]) > 2147483647
			|| ft_atoi_long((const char *)av[ac]) < -2147483648)
			return (ft_error("Wrong input ! One argument is bigger than an integer : ", av[ac]));
	}
	if (ft_has_dup_tab(av))
		return (ft_error("Wrong input ! Check for duplicates...", ""));
	return (0);
}

/*
** Checks if the final a_stack is correctly ordered.
*/

int	ft_is_solved(t_list *a, int print)
{
	int	prev;
	int	suiv;

	prev = ft_atoi(a->content);
	while (ft_strcmp(a->next->content, "a"))
	{
		suiv = ft_atoi(a->next->content);
		if (prev > suiv)
		{
			if (print)
				ft_putstr_endl("KO");
			return (0);
		}
		prev = suiv;
		a = a->next;
	}
	if (print)
		ft_putstr_endl("OK");
	return (1);
}
