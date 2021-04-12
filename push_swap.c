/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 23:56:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_min(t_list **a)
{
	int	min;
	t_list	*tmp;

	min = ft_atoi((*a)->content);
	tmp = *a;
	while (ft_strcmp((*a)->next->content, "a"))
	{
		(*a) = (*a)->next;
		if (min > ft_atoi((*a)->content))
			min = ft_atoi((*a)->content);
	}
	*a = tmp;
	return (min);
}

void	elaborate(t_list **a, t_list **b)
{
	int	min;
	int	middle;
	int	min_pos;

	while (!ft_is_solved(*a, 0) && ft_strcmp((*a)->content, "a"))
	{
//		printf("DANS LA BOCLE WHILE D ELABORATE\n");
		ft_display(*a, *b);
		if (ft_strcmp((*a)->content, "a"))
		{
			middle = ft_lstsize(*a) / 2;
			min = find_min(a);
			min_pos = ft_min_position(*a, min);
			if (ft_atoi((*a)->content) == min)
				pb(a, b, 1);
			else if (ft_strcmp((*a)->content, "a") && min_pos <= middle)
				ra(a, b, 1);
			else if (ft_strcmp((*a)->content, "a") && min_pos > middle)
				rra(a, b, 1);
		//	printf("MARQUEUâR min = %d, min_pos = %d, middle = %d\n", min, min_pos, middle);
		}
//		printf("Fin de la boucle while de elaborate\n");
	}
	ft_display(*a, *b);
	while (ft_strcmp((*b)->content, "b"))
		pa(a, b, 1);
	ft_display(*a, *b);
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
