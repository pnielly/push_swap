/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:47:27 by user42            #+#    #+#             */
/*   Updated: 2021/04/28 17:59:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	elab_101(t_list **a, t_list **b)
{
	int	thr_inf;
	int	thr_sup;
	int	groups;
	int	count;

	if (ft_is_solved(*a, 0))
		return ;
	groups = ft_lstsize(*a) / 4;
	count = 0;
	thr_inf = BORNE_SUP;
	while (!(ft_is_solved(*a, 0) && ft_lstsize(*b) == 1))
	{
		count++;
		thr_sup = thr_inf;
		thr_inf = find_n_max(*a, groups * count);
		while (remains_in_a(*a, thr_inf, thr_sup))
			fill_b(a, b, thr_inf, thr_sup);
		calibrate_a(a, b);
		while (ft_lstsize(*b) > 1)
			pa(a, b, 1);
	}
}

void	elab_500(t_list **a, t_list **b)
{
	int	thr_inf;
	int	thr_sup;
	int	groups;
	int	count;

	if (ft_is_solved(*a, 0))
		return ;
	groups = ft_lstsize(*a) / 9;
	count = 0;
	thr_inf = BORNE_SUP;
	while (!(ft_is_solved(*a, 0) && ft_lstsize(*b) == 1))
	{
		count++;
		thr_sup = thr_inf;
		thr_inf = find_n_max(*a, groups * count);
		while (remains_in_a(*a, thr_inf, thr_sup))
			fill_b(a, b, thr_inf, thr_sup);
		calibrate_a(a, b);
		while (ft_lstsize(*b) > 1)
			pa(a, b, 1);
	}
}
