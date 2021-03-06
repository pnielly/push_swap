/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:09:08 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 23:31:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_clear(t_list **a)
{
	t_list	*curr;
	t_list	*next;

	if (!a || !*a)
		return (0);
	curr = *a;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
	*a = NULL;
	return (0);
}

int	ft_error(char *str, char *pb)
{
	ft_putstr_fd("Error\n", 2);
	(void)pb;
	(void)str;
	return (1);
}

int	ft_isnumlist(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isnum(s + i))
			return (0);
	}
	return (1);
}

/*
** Checks for errors in the original input from the user
*/

int	ft_check_for_error(int ac, char **av)
{
	if (ac == 1)
		return (2);
	while (--ac)
	{
		if (!ft_isnumlist(av[ac]) && !(ac == 1 && !ft_strcmp(av[ac], "-v")))
			return (ft_error("Wrong input ! Only digits allowed : ", av[ac]));
		if (ft_atoi_long((const char *)av[ac]) > 2147483647
			|| ft_atoi_long((const char *)av[ac]) < -2147483648)
			return (ft_error("Wrong input ! One argument is bigger \
			than an integer : ", av[ac]));
	}
	return (0);
}

/*
** Checks if the final a_stack is correctly ordered.
*/

int	ft_is_solved(t_list *a, int print)
{
	int	prev;
	int	suiv;

	if (!ft_strcmp(a->content, "a"))
		return (1);
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
