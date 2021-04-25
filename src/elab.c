/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:36:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/25 10:57:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	elab_3(t_list **a, t_list **b)
{
	if (ft_is_solved(*a, 0))
		return ;
	else if (ft_position(*a, find_min(*a) == 1))
	{
		sa(a, b, 1);
		ra(a, b, 1);
	}
	else if (ft_position(*a, find_max(*a) == 1))
	{
		if (ft_position(*a, find_min(*a) == 3))
		{
			sa(a, b, 1);
			rra(a, b, 1);
		}
		else
			ra(a, b, 1);
	}
	else if (ft_position(*a, find_max(*a) == 2))
		rra(a, b, 1);
	else
		sa(a, b, 1);
}

void	elab_11(t_list **a, t_list **b)
{
	int	vb;

	while (ft_lstsize(*a) > 4)
		pb(a, b, 1);
	elab_3(a, b);
	while (ft_lstsize(*b) > 1)
	{
		vb = ft_atoi((*b)->content);
		if (vb > find_max(*a) || vb < find_min(*a))
		{
			while (ft_position(*a, find_max(*a)) != ft_lstsize(*a) - 1)
				rra(a, b, 1);
		}
		else
		{
			while (ft_position(*a, find_floor(*a, vb)) != 1)
				rra(a, b, 1);
		}
		pa(a, b, 1);
	}
	if (ft_position(*a, find_min(*a)) < ft_lstsize(*a) / 2)
	{
		while (!ft_is_solved(*a, 0))
			ra(a, b, 1);
	}
	else
	{
		while (!ft_is_solved(*a, 0))
			rra(a, b, 1);
	}
}

/*
** The 2 first lines aim at getting groups of 10 numbers.
*/

void	elab_101(t_list **a, t_list **b)
{
	int	top_next;
	int	bot_next;
	int	groups;
	int	thr;

	groups = ft_lstsize(*a) / 10;
	groups = ft_lstsize(*a) / groups;
	thr = find_n_min(*a, 10);
	while (!ft_is_solved(*a, 0))
	{
		top_next = ft_position(find_top_next(*a, thr));
		bot_next = ft_position(find_bot_next(*a, thr));
		if (top_next < ft_lstsize(*a) - 1 - bot_next)
		{
			top_next = find_top_next(*a, thr);
			while (ft_position(*a, top_next) != 1)
				ra(a, b, 1);
		}
		else
		{
			bot_next = find_bot_next(*a, thr);
			while (ft_position(*a, bot_next) != 1)
				rra(a, b, 1);
		}
		pb(a, b, 1);
	}
}
