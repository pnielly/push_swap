/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 20:17:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	b_solved(t_list *b)
{
	if (ft_lstsize(b) <= 2)
		return (1);
	while (ft_strcmp(b->next->content, "b"))
	{
		if (ft_atoi(b->content) < ft_atoi(b->next->content))
			return (0);
		b = b->next;
	}
	return (1);
}

void	elaborate(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 4)
		elab_3(a, b);
	else if (ft_lstsize(*a) <= 11)
		elab_11(a, b);
/*	else if (ft_lstsize(*a) <= 101)
		elab_100(a, b);
	else
		elab_500(a, b);*/
	return ;
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
