/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:47:27 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 13:22:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	elab_101(t_list **a, t_list **b, int print)
{
	int	groups;
	int	count;
	int	thr[2];

	if (ft_is_solved(*a, 0))
		return ;
	groups = ft_lstsize(*a) / 4;
	count = 0;
	thr[0] = BORNE_SUP;
	while (!(ft_is_solved(*a, 0) && ft_lstsize(*b) == 1))
	{
		count++;
		thr[1] = thr[0];
		thr[0] = find_n_max(*a, groups * count);
		while (remains_in_a(*a, thr[0], thr[1]))
			fill_b(a, b, thr, print);
		calibrate_a(a, b, print);
		while (ft_lstsize(*b) > 1)
			pa(a, b, (1 + print));
		while (groups * count > ft_lstsize(*a) && !ft_is_solved(*a, 0))
			rra(a, b, (1 + print));
	}
}

void	elab_500(t_list **a, t_list **b, int print)
{
	int	groups;
	int	count;
	int	thr[2];

	if (ft_is_solved(*a, 0))
		return ;
	groups = ft_lstsize(*a) / 9;
	count = 0;
	thr[0] = BORNE_SUP;
	while (!(ft_is_solved(*a, 0) && ft_lstsize(*b) == 1))
	{
		count++;
		thr[1] = thr[0];
		thr[0] = find_n_max(*a, groups * count);
		while (remains_in_a(*a, thr[0], thr[1]))
			fill_b(a, b, thr, print);
		calibrate_a(a, b, print);
		while (ft_lstsize(*b) > 1)
			pa(a, b, (1 + print));
		while (groups * count > ft_lstsize(*a) && !ft_is_solved(*a, 0))
			rra(a, b, (1 + print));
	}
}
