/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/05/03 18:39:32 by user42           ###   ########.fr       */
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
	else if (ft_lstsize(*a) <= 101)
		elab_101(a, b);
	else
		elab_500(a, b);
	return ;
}

void	buildup_a_stack(t_list **a_stack, int ac, char **av, int i)
{
	int		j;

	while (i < ac)
	{
		j = ft_strlen(av[ac - i]);
		while (j >= 0)
		{
			while (j > 0 && !ft_isdigit(av[ac - i][j]))
				j--;
			while (j > 0 && ft_isdigit(av[ac - i][j]))
				j--;
			if (j >= 0)
				ft_lstadd_front(a_stack,
					ft_lstnew(av[ac - i] + j));
			j--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		i;

	if (ft_check_for_error(ac, av) == 2)
		ft_error("Empty arg ! ", "You need to give me some numbers");
	if (ft_check_for_error(ac, av))
		return (0);
	a_stack = ft_lstnew("a");
	i = 1;
	buildup_a_stack(&a_stack, ac, av, i);
	b_stack = ft_lstnew("b");
	elaborate(&a_stack, &b_stack);
	ft_clear(&a_stack);
	ft_clear(&b_stack);
	return (0);
}
