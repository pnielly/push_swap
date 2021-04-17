/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 20:13:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_is_solved(t_list *b)
{
	while (b->next)
	{
		if (ft_atoi(b->next->content) > ft_atoi(b->content))
			return (0);
		b = b->next;
	}
	if (ft_lstsize(b) <= 2)
		return (0);
	return (1);
}

int	swap_needed(t_list *a, char stack)
{
	int	bigger;

	if (!ft_strcmp(a->content, "b") || !ft_strcmp(a->content, "a"))
		return (0);
	bigger = 0;
	if (ft_atoi(a->content) > ft_atoi(a->next->content))
		bigger = 1;
	if (((stack == 'a' && bigger) || (stack == 'b' && !bigger)) && ft_lstsize(a))
		return (1);
	return (0);
}

int	ft_min_position(t_list *a, int min)
{
	int	i;

	i = 1;
	while (a && ft_atoi(a->content) != min)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	find_min(t_list *a)
{
	int	min;
	t_list	*tmp;

	min = ft_atoi(a->content);
	tmp = a;
	while (a->next && ft_strcmp(a->next->content, "a"))
	{
		a = a->next;
		if (min > ft_atoi(a->content))
			min = ft_atoi(a->content);
	}
	a = tmp;
	return (min);
}

// find the n-th smallest element of the list
int	find_n_min(t_list *a, int n)
{
	int	min;
	t_list	*tmp;

	tmp = a;
	while (--n > 0)
	{
		min = find_min(tmp);
		ft_lst_rm_one(&tmp, ft_min_position(tmp, min));
	}
	return (find_min(tmp));
}

void	handle_swap(t_list **a, t_list **b)
{
	int	swap_a;
	int	swap_b;

	swap_a = swap_needed(*a, 'a');
	swap_b = swap_needed(*b, 'b');
	if (swap_a && swap_b)
		ss(a, b, 1);
	else if (swap_a && !swap_b)
		sa(a, b, 1);
	else if (!swap_a && swap_b)
		sb(a, b, 1);
}

char	get_dist_min(t_list *a, int min)
{
	int	deb;
	int	end;

	deb = 1;
	while (ft_atoi(a->content) > min && a->next)
	{
		a = a->next;
		deb++;
	}
	end = 1;
	while (a->next)
	{
		a = a->next;
		end++;
	}
	if (end > deb)
		return ('d');
	else
		return ('e');
}

void	handle_rotate(t_list **a, t_list **b, int min)
{
	char	dist_min;
	int	rot_b;

	dist_min = get_dist_min(*a, min);
	rot_b = 0;
	if (!b_is_solved(*b))
		rot_b = 1;
	if (dist_min == 'd' && rot_b)
		rr(a, b, 1);
	else if (dist_min == 'd' && !rot_b)
		ra(a, b, 1);
	else if (dist_min == 'e' && rot_b)
		rrr(a, b, 1);
	else if (dist_min == 'e' && !rot_b)
		rra(a, b, 1);
}

void	elaborate(t_list **a, t_list **b)
{
	int	min;
	int	middle;
	int	min_pos;
	t_list	*tmp;

	middle = ft_lstsize(*a) / 2;
	ft_lstcopy(a, &tmp);
	min = find_n_min(tmp, middle);
	min_pos = ft_min_position(*a, min);
	while (!ft_is_solved(*a, 0) && !b_is_solved(*b))
	{
//		printf("LOLOLOLO %d\n", middle);
		while (ft_atoi((*a)->content) <= min)
			pb(a, b, 1);
		handle_swap(a, b);
//		ft_display(*a, *b);
		while (ft_atoi((*a)->content) <= min)
			pb(a, b, 1);
		handle_rotate(a, b, min);
//		ft_display(*a, *b);
	}
//	ft_display(*a, *b);
	while (ft_lstsize(*b) > 1)
		pa(a, b, 1);
//	ft_display(*a, *b);
}

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*tmp;
	int	i;

	if (ft_check_for_error(ac, av))
		return (0);
	a_stack = ft_lstnew(av[1]);
	b_stack = ft_lstnew("b");
	i = 1;
	tmp = a_stack;
	while (i < ac - 1)
	{
		tmp->next = ft_lstnew(av[i + 1]);
		tmp = tmp->next;
		i++;
	}
	tmp->next = ft_lstnew("a");
	elaborate(&a_stack, &b_stack);
	return (0);
}
