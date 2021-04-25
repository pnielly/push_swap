/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 20:08:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_floor(t_list *a, int next)
{
	int	floor;
	int	va;
	
	floor = find_max(a);
	while (ft_strcmp(a->content, "a"))
	{
		va = ft_atoi(a->content);
		if (va > next && va < floor)
			floor = va;
		a = a->next;
	}
	return (floor);
}

int	ft_find_next(t_list *a, int min)
{
	int	deb;
	int	end;
	t_list	*tmp;

	tmp = a;
	while (ft_atoi(a->content) > min && ft_strcmp(a->content, "a"))
		a = a->next;
	if (ft_strcmp(a->content, "a"))
	{
		deb = ft_atoi(a->content);
		end = deb;
		while (ft_strcmp(a->next->content, "a"))
		{
			a = a->next;
			if (ft_atoi(a->content) <= min)
				end = ft_atoi(a->content);
		}
	}
	else
	{
		deb = find_min(tmp);
		end = deb;
	}
	if (ft_position(tmp, deb) <= ft_lstsize(tmp) - ft_position(tmp, end))
		return (deb);
	return (end);
}

int	ft_last_elem_value(t_list *a)
{
	if (ft_lstsize(a) > 1)
	{
		while (a->next->next)
			a = a->next;
	}
	return (ft_atoi(a->content));
}
