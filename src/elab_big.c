/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elab_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:33:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 00:36:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"


int	ft_suivant(t_list *tmp, int prec)
{
	int	suiv;

	suiv = BORNE_SUP;
	while (ft_strcmp(tmp->content, "a"))
	{
		if (ft_atoi(tmp->content) > prec && ft_atoi(tmp->content) < suiv)
			suiv = ft_atoi(tmp->content);
		tmp = tmp->next;
	}
//	ft_putstr("suiv = ");
//	ft_putstr_endl(ft_itoa(suiv));
//	ft_putstr("prec = ");
//	ft_putstr_endl(ft_itoa(prec));
	return (suiv);
}

int	remains_in_a(t_list *a, int thr_inf, int thr_sup)
{
	t_list	*tmp;

	ft_lstcopy(&a, &tmp);
	while (ft_strcmp(a->content, "a"))
	{
		if (ft_atoi(a->content) >= thr_inf && ft_atoi(a->content) < thr_sup)
		{
//			ft_putstr("REMAINING = ");
//			ft_putstr_endl((char *)a->content);
	/*		if (ft_atoi(a->next->content) == ft_suivant(tmp, ft_atoi(a->content)))
				a = a->next;
			else
			{*/
				ft_clear(&tmp);
				return (1);
		/*	}*/
		}
		a = a->next;
	}
	ft_clear(&tmp);
	return (0);
}

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
//				ft_display(*a, *b);
	}
}

void	fill_b(t_list **a, t_list **b, int thr_inf, int thr_sup)
{
	int	next;
	int	floor;

	next = ft_find_next(*a, thr_inf, thr_sup);
/*	ft_putstr("next = ");
	ft_putstr_endl(ft_itoa(next));
	ft_putstr("thr_inf = ");
	ft_putstr_endl(ft_itoa(thr_inf));
	ft_putstr("thr_sup = ");
	ft_putstr_endl(ft_itoa(thr_sup));*/
	floor = find_floor_b(*b, next);
/*	ft_putstr("floor = ");
	ft_putstr_endl(ft_itoa(floor));*/
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
//	ft_putstr("ft_atoi(b->conetnt) ======= ");
//	ft_putstr_endl((char *)(*b)->content);
		while (ft_atoi((*b)->content) != floor && ft_lstsize(*b) > 1)
		{
			if (ft_position(*b, floor) > ft_lstsize(*b) / 2)
				rrb(a, b, 1);
			else
				rb(a, b, 1);
//	ft_putstr("magic floor = ");
//	ft_putstr_endl(ft_itoa(floor));

		}
	pb(a, b, 1);
	if (!remains_in_a(*a, thr_inf, thr_sup))
		order_b(b, a);
//	ft_putstr("next = ");
//	ft_putstr_endl(ft_itoa(next));
//	ft_putstr_endl(ft_itoa(floor));
//	ft_display(*a, *b);

}

void	calibrate_a(t_list **a, t_list **b)
{
	int	floor;

	floor = find_floor_a(*a, find_max(*b));
//	ft_putstr("Calibrate on the floor = ");
//	ft_putstr_endl(ft_itoa(floor));
	while (floor != ft_atoi((*a)->content))
	{
		if (ft_position(*a, floor) > ft_lstsize(*a) / 2)
			rra(a, b, 1);
		else
			ra(a, b, 1);
	}
}

void	elab_101(t_list **a, t_list **b)
{
	int	thr_inf;
	int	thr_sup;
	int	groups;
	int	count;

	groups = ft_lstsize(*a) / 10;
	groups = ft_lstsize(*a) / groups;
	count = 0;
	thr_inf = BORNE_SUP;
	while (!(ft_is_solved(*a, 0) && ft_lstsize(*b) == 1))
	{
		count++;
		thr_sup = thr_inf;
		thr_inf = find_n_max(*a, groups * count);
/*		ft_putstr("Ej suis borne inf :");
		ft_putstr_endl(ft_itoa(thr_inf));*/
		while (/*ft_lstsize(*b) < groups + 1 &&*/ remains_in_a(*a, thr_inf, thr_sup))
			fill_b(a, b, thr_inf, thr_sup);
		calibrate_a(a, b);
		while (ft_lstsize(*b) > 1)
			pa(a, b, 1);
		//		ft_display(*a, *b);
	}
}

/*
 ** The 2 first lines aim at getting groups of 10 numbers.
 ** thr is the threshold between each group
 */
/*
   void	elab_101(t_list **a, t_list **b)
   {
   int	top_next;
   int	bot_next;
   int	groups;
   int	thr_sup;
   int	thr_inf;
   int	count;

   printf("0\n");
   groups = ft_lstsize(*a) / 10;
   groups = ft_lstsize(*a) / groups;
   printf("1\n");
   count = -1;
   thr_sup = 1;
   while (!ft_is_solved(*a, 0))
   {
   ++count;
   printf("2\n");
   if (!count)
   {
   thr_sup = find_n_min(*a, groups);
   thr_inf = find_min(*a);
//			printf("thr_inf = %d, thr_sup = %d\n", thr_inf, thr_sup);
}
else
{
thr_inf = thr_sup + 1;
thr_sup = find_n_min(*a, groups * count);
}
//		printf("3\n");
while (find_top_next(*a, thr_inf, thr_sup) != find_bot_next(*a, thr_inf, thr_sup))
{
top_next = ft_position(*a, find_top_next(*a, thr_inf, thr_sup));
bot_next = ft_position(*a, find_bot_next(*a, thr_inf, thr_sup));
if (top_next < ft_lstsize(*a) - 1 - bot_next)
{
top_next = find_top_next(*a, thr_inf, thr_sup);
//				printf("4\n");
while (ft_position(*a, top_next) != 1 && ft_lstsize(*b) > 1)
{
if (ft_position(*b, find_floor(*b, top_next) == 1))
ra(a, b, 1);
else
rr(a, b, 1);
}
}
else
{
top_next = find_bot_next(*a, thr_inf, thr_sup);
//				printf("4.2\n");
while (ft_position(*a, top_next) != 1 && ft_lstsize(*b) > 1)
{
//					printf("4.3\n");
//					printf("caca\n");
ft_display(*a, *b);
if (ft_position(*b, find_floor(*b, top_next) == 1))
rra(a, b, 1);
else
rrr(a, b, 1);
//					printf("4.4\n");
}
}
//			printf("5\n");
//			printf("top_next = %d\n", top_next);
while (ft_position(*b, find_floor(*b, top_next)) != 1 && ft_lstsize(*b) > 1)
{
if (ft_position(*b, find_floor(*b, top_next)) > ft_lstsize(*b) / 2)
rrb(a, b, 1);
else
rb(a, b, 1);
//		printf("ft position = %d et floor = %d\n", ft_position(*b, find_floor(*b, top_next)), find_floor(*b, top_next));
}
pb(a, b, 1);
}
while (!b_is_solved(*b, *a))
	rb(a, b, 1);
	printf("group = %d, thr_inf = %d, thr_sup = %d, count = %d\n", groups, thr_inf, thr_sup, count);
	printf("6\n");
	bot_next = -1;
while (++bot_next < groups)
	pa(a, b, 1);
	ft_display(*a, *b);
	}
}*/
