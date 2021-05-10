/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 12:57:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
** Finds the position of the element with value min
*/
int	ft_position(t_list *a, int min)
{
	int	i;

	i = 1;
	if (ft_lstsize(a) <= 1)
		return (0);
	while (a && ft_atoi(a->content) != min)
	{
		i++;
		a = a->next;
	}
	return (i);
}

/*
 ** Find the element of the list with the min int value
 */
int	find_min(t_list *a)
{
	int		min;

	if (ft_lstsize(a) <= 2)
		return (ft_atoi(a->content));
	min = ft_atoi(a->content);
	while (ft_strcmp(a->next->content, "a") && ft_strcmp(a->next->content, "b"))
	{
		a = a->next;
		if (min > ft_atoi(a->content))
			min = ft_atoi(a->content);
	}
	return (min);
}

/*
 ** Find the element of the list with the max int value
 */
int	find_max(t_list *a)
{
	int		max;

	max = ft_atoi(a->content);
	while (ft_strcmp(a->content, "a") && ft_strcmp(a->content, "b"))
	{
		a = a->next;
		if (max < ft_atoi(a->content))
			max = ft_atoi(a->content);
	}
	return (max);
}

/*
 ** see find_n_max()
 */
int	ft_below(int max, t_list *a)
{
	int	below;
	int	va;

	below = find_min(a);
	while (ft_strcmp(a->content, "a") && ft_strcmp(a->content, "b"))
	{
		va = ft_atoi(a->content);
		if (va > below && va < max)
			below = va;
		a = a->next;
	}
	return (below);
}

/*
 ** find the n-th biggest element of the list
 */
int	find_n_max(t_list *a, int n)
{
	int	max;

	if (n > ft_lstsize(a))
		return (0);
	max = find_max(a);
	while (--n > 0)
		max = ft_below(max, a);
	return (max);
}
