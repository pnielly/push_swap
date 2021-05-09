/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:32:57 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 13:00:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	elab_3(t_list **a, t_list **b, int print)
{
	if (ft_is_solved(*a, 0))
		return ;
	else if (ft_position(*a, find_min(*a)) == 1)
	{
		sa(a, b, (1 + print));
		ra(a, b, (1 + print));
	}
	else if (ft_position(*a, find_max(*a)) == 1)
	{
		if (ft_position(*a, find_min(*a)) == 3)
		{
			sa(a, b, (1 + print));
			rra(a, b, (1 + print));
		}
		else
			ra(a, b, 1 + print);
	}
	else if (ft_position(*a, find_max(*a)) == 2)
		rra(a, b, (1 + print));
	else
		sa(a, b, (1 + print));
}

void	solving_a(t_list **a, t_list **b, int print)
{
	while (!ft_is_solved(*a, 0))
	{
		if (ft_position(*a, find_min(*a)) > ft_lstsize(*a) / 2)
			rra(a, b, (1 + print));
		else
			ra(a, b, (1 + print));
	}
}

void	elab_11(t_list **a, t_list **b, int print)
{
	int	vb;

	if (ft_is_solved(*a, 0))
		return ;
	while (ft_lstsize(*a) > 4)
		pb(a, b, (1 + print));
	elab_3(a, b, print);
	while (ft_lstsize(*b) > 1)
	{
		vb = ft_atoi((*b)->content);
		if (vb > find_max(*a) || vb < find_min(*a))
		{
			while (ft_position(*a, find_max(*a)) != ft_lstsize(*a) - 1)
				rra(a, b, (1 + print));
		}
		else
		{
			while (ft_position(*a, find_floor_a(*a, vb)) != 1)
				rra(a, b, (1 + print));
		}
		pa(a, b, (1 + print));
	}
	solving_a(a, b, print);
}
