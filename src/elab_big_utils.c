/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:47:15 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 12:53:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
 ** Checks if there is still a number in a_stack to push to b_stack
 */
int	remains_in_a(t_list *a, int thr_inf, int thr_sup)
{
	t_list	*tmp;

	ft_lstcopy(&a, &tmp);
	while (ft_strcmp(a->content, "a"))
	{
		if (ft_atoi(a->content) >= thr_inf && ft_atoi(a->content) < thr_sup)
		{
			ft_clear(&tmp);
			return (1);
		}
		a = a->next;
	}
	ft_clear(&tmp);
	return (0);
}

/*
 ** Puts max of b_stack on top of b_stack
 */
void	order_b(t_list **b, t_list **a)
{
	int	max;

	max = find_max(*b);
	while (!b_is_solved(*b, *a))
	{
		if (ft_position(*b, max) > ft_lstsize(*b) / 2)
			rrb(a, b, 1);
		else
			rb(a, b, 1);
	}
}

void	get_on_top_of_a(t_list **a, t_list **b, int next, int floor)
{
	while (ft_atoi((*a)->content) != next)
	{
		if (ft_position(*a, next) > ft_lstsize(*a) / 2)
		{
			if (ft_atoi((*b)->content) != floor)
				rrr(a, b, 1);
			else
				rra(a, b, 1);
		}
		else
		{
			if (ft_atoi((*b)->content) != floor)
				rr(a, b, 1);
			else
				ra(a, b, 1);
		}
	}
}

void	fill_b(t_list **a, t_list **b, int thr_inf, int thr_sup)
{
	int	next;
	int	floor;

	next = ft_find_next(*a, thr_inf, thr_sup);
	floor = find_floor_b(*b, next);
	get_on_top_of_a(a, b, next, floor);
	while (ft_atoi((*b)->content) != floor && ft_lstsize(*b) > 1)
	{
		if (ft_position(*b, floor) > ft_lstsize(*b) / 2)
			rrb(a, b, 1);
		else
			rb(a, b, 1);
	}
	pb(a, b, 1);
	if (!remains_in_a(*a, thr_inf, thr_sup))
		order_b(b, a);
}

/*
 ** Puts the number that is right next to the max of b_stack
 ** on top of a_stack
 */

void	calibrate_a(t_list **a, t_list **b)
{
	int	floor;

	floor = find_floor_a(*a, find_max(*b));
	while (floor != ft_atoi((*a)->content))
	{
		if (ft_position(*a, floor) > ft_lstsize(*a) / 2)
			rra(a, b, 1);
		else
			ra(a, b, 1);
	}
}
