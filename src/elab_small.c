/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:32:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/28 18:04:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	elab_3(t_list **a, t_list **b)
{
	if (ft_is_solved(*a, 0))
		return ;
	else if (ft_position(*a, find_min(*a)) == 1)
	{
		sa(a, b, 1);
		ra(a, b, 1);
	}
	else if (ft_position(*a, find_max(*a)) == 1)
	{
		if (ft_position(*a, find_min(*a)) == 3)
		{
			sa(a, b, 1);
			rra(a, b, 1);
		}
		else
			ra(a, b, 1);
	}
	else if (ft_position(*a, find_max(*a)) == 2)
		rra(a, b, 1);
	else
		sa(a, b, 1);
}

void	solving_a(t_list **a, t_list **b)
{
	while (!ft_is_solved(*a, 0))
	{
		if (ft_position(*a, find_min(*a)) > ft_lstsize(*a) / 2)
			rra(a, b, 1);
		else
			ra(a, b, 1);
	}
}

void	elab_11(t_list **a, t_list **b)
{
	int	vb;

	if (ft_is_solved(*a, 0))
		return ;
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
			while (ft_position(*a, find_floor_a(*a, vb)) != 1)
				rra(a, b, 1);
		}
		pa(a, b, 1);
	}
	solving_a(a, b);
}
