/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 18:10:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
 ** Checks if b_stack is ordered
 */
int	b_is_solved(t_list *b, t_list *a)
{
	t_list	*tmp;

	tmp = b;
	while (tmp->next)
	{
		if (ft_atoi(tmp->next->content) > ft_atoi(tmp->content))
			return (0);
		tmp = tmp->next;
	}
	(void)a;
	return (1);
}

int	find_floor_b(t_list *b, int next)
{
	int	floor;
	int	vb;

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
	}
	return (floor);
}

int	find_floor_a(t_list *a, int next)
{
	int	floor;
	int	va;

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
	}
	return (floor);
}

int	ft_find_next(t_list *a, int min, int max)
{
	int		deb;
	int		end;
	t_list	*tmp;

	tmp = a;
	while ((ft_atoi(a->content) >= max || ft_atoi(a->content) < min)
		&& ft_strcmp(a->content, "a"))
	{
		a = a->next;
	}
	deb = ft_atoi(a->content);
	end = deb;
	while (a->next && ft_strcmp(a->next->content, "a"))
	{
		a = a->next;
		if (ft_atoi(a->content) < max && ft_atoi(a->content) >= min)
			end = ft_atoi(a->content);
	}
	if (ft_position(tmp, deb) <= ft_lstsize(tmp) - ft_position(tmp, end))
		return (deb);
	return (end);
}
