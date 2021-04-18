/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 22:49:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	swap_needed(t_list *a, char stack)
{
	int	bigger;

	if (!ft_strcmp(a->content, "b") || !ft_strcmp(a->content, "a"))
		return (0);
	bigger = 0;
	if (ft_atoi(a->content) > ft_atoi(a->next->content))
		bigger = 1;
	if (((stack == 'a' && bigger) || (stack == 'b' && !bigger)))
		return (1);
	return (0);
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
	else
		return ;
}

void	handle_rotate(t_list **a, t_list **b, int min)
{
	char	dist_min;
	int		rot_b;

	dist_min = get_dist_min(*a, min);
	rot_b = 0;
	if (ft_is_solved(*a, 0) && b_is_solved(*b, *a))
		return ;
	if (!b_is_solved(*b, *a))
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

/*
** Strategy : split the series in two stacks :
** stack a shelters the 50% biggest numbers
** stack b shelters the 50% smallest numbers
** --> this way we optimize the sorting by using rrr and rr
*/
void	elaborate(t_list **a, t_list **b)
{
	int		min;
	int		middle;
	t_list	*tmp;

	middle = ft_lstsize(*a) / 2;
	ft_lstcopy(a, &tmp);
	min = find_n_min(tmp, middle);
	while (!(ft_is_solved(*a, 0) && b_is_solved(*b, *a)
			&& (ft_atoi((*a)->content) > ft_atoi((*b)->content))))
	{
		while (ft_atoi((*a)->content) <= min)
			pb(a, b, 1);
		handle_swap(a, b);
		while (ft_atoi((*a)->content) <= min)
			pb(a, b, 1);
		handle_rotate(a, b, min);
	}
	while (ft_lstsize(*b) > 1)
		pa(a, b, 1);
	ft_clear(a);
	ft_clear(b);
	ft_clear(&tmp);
}

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*tmp;
	int		i;

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
