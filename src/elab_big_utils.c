/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:47:15 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 13:37:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
 ** Checks if there is still a number in a_stack to push to b_stack
 */
int	remains_in_a(t_list *a, int thr_inf, int thr_sup)
{
	while (ft_strcmp(a->content, "a"))
	{
		if (ft_atoi(a->content) >= thr_inf && ft_atoi(a->content) < thr_sup)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
 ** Puts max of b_stack on top of b_stack
 */
void	order_b(t_list **b, t_list **a, int print)
{
	int	max;

	max = find_max(*b);
	while (!b_is_solved(*b, *a))
	{
		if (ft_position(*b, max) > ft_lstsize(*b) / 2)
			rrb(a, b, (1 + print));
		else
			rb(a, b, (1 + print));
	}
}

void	get_on_top_of_a(t_list **a, t_list **b, int *tab, int print)
{
	int	next;
	int	floor;

	next = tab[0];
	floor = tab[1];
	while (ft_atoi((*a)->content) != next)
	{
		if (ft_position(*a, next) > ft_lstsize(*a) / 2)
		{
			if (ft_atoi((*b)->content) != floor)
				rrr(a, b, (1 + print));
			else
				rra(a, b, (1 + print));
		}
		else
		{
			if (ft_atoi((*b)->content) != floor)
				rr(a, b, (1 + print));
			else
				ra(a, b, (1 + print));
		}
	}
}

/*
** next is the next nb to push from a to b
** floor is the biggest nb in b that is smaller than next
*/

void	fill_b(t_list **a, t_list **b, int *thr, int print)
{
	int	next;
	int	floor;
	int	tab[2];

	next = ft_find_next(*a, thr[0], thr[1]);
	floor = find_floor_b(*b, next);
	tab[0] = next;
	tab[1] = floor;
	get_on_top_of_a(a, b, tab, print);
	while (ft_atoi((*b)->content) != floor && ft_lstsize(*b) > 1)
	{
		if (ft_position(*b, floor) > ft_lstsize(*b) / 2)
			rrb(a, b, (1 + print));
		else
			rb(a, b, (1 + print));
	}
	pb(a, b, 1 + print);
	if (!remains_in_a(*a, thr[0], thr[1]))
		order_b(b, a, print);
}

/*
 ** Puts the number that is right next to the max of b_stack
 ** on top of a_stack
 */

void	calibrate_a(t_list **a, t_list **b, int print)
{
	int	floor;

	floor = find_floor_a(*a, find_max(*b));
	while (floor != ft_atoi((*a)->content))
	{
		if (ft_position(*a, floor) > ft_lstsize(*a) / 2)
			rra(a, b, (1 + print));
		else
			ra(a, b, (1 + print));
	}
}
