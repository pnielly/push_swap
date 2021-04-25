/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 00:35:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_floor_b(t_list *b, int next)
{
	int	floor;
	int	vb;

//printf("JOJO %d\n", next);
	if (!ft_strcmp(b->content, "a"))
		return ('a');
	if (!ft_strcmp(b->content, "b"))
		return ('b');
	if (next < find_min(b) || next > find_max(b))
		return (find_max(b));
	floor = find_min(b);
	while (ft_strcmp(b->content, "b") && ft_strcmp(b->content, "a"))
	{
		vb = ft_atoi(b->content);
		if (vb < next && vb > floor)
			floor = vb;
		b = b->next;
//	printf("JOJO END a->ocntnt = %s\n", (char *)b->content);
	}
	return (floor);
}

int	find_floor_a(t_list *a, int next)
{
	int	floor;
	int	va;

//printf("JOJO %d\n", next);
	if (!ft_strcmp(a->content, "a"))
		return ('a');
	if (!ft_strcmp(a->content, "b"))
		return ('b');
	if (next < find_min(a) || next > find_max(a))
		return (find_min(a));
	floor = find_max(a);
	while (ft_strcmp(a->content, "b") && ft_strcmp(a->content, "a"))
	{
		va = ft_atoi(a->content);
		if (va > next && va < floor)
			floor = va;
		a = a->next;
//	printf("JOJO END a->ocntnt = %s\n", (char *)a->content);
	}
//	printf(" floor = %d and next = %d\n", floor, next);
	return (floor);
}

int	ft_find_next(t_list *a, int min, int max)
{
	int	deb;
	int	end;
	t_list	*tmp;

	tmp = a;
//	ft_putstr("FIRST OF A:");
//	ft_putstr_endl((char *)a->content);
	while ((ft_atoi(a->content) >= max || ft_atoi(a->content) < min) && ft_strcmp(a->content, "a"))
		a = a->next;
	if (ft_strcmp(a->content, "a"))
	{
		deb = ft_atoi(a->content);
		end = deb;
		while (ft_strcmp(a->next->content, "a"))
		{
			a = a->next;
			if (ft_atoi(a->content) < max && ft_atoi(a->content) >= min)
			{
//				ft_putstr_endl("HARICOT\n");
//				ft_putstr_endl((char *)a->content);
				end = ft_atoi(a->content);
			}
		}
	}
	else
	{
//		ft_putstr_endl("HARICOT VERT\n");
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
