/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 20:36:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	elaborate(t_list **a, t_list **b, int print)
{
	if (ft_lstsize(*a) <= 4)
		elab_3(a, b, print);
	else if (ft_lstsize(*a) <= 11)
		elab_11(a, b, print);
	else if (ft_lstsize(*a) <= 101)
		elab_101(a, b, print);
	else
		elab_500(a, b, print);
	return ;
}

void	buildup_add_nb(t_list **a_stack, char *nb, int j)
{	
	if (!j)
		ft_lstadd_front(a_stack, ft_lstnew(ft_strtrim(nb, SPACE)));
	else
		ft_lstadd_front(a_stack, ft_lstnew(ft_strtrim(nb + 1, SPACE)));
}

/*
** Creating a chained list called "a stack" where each element is a number
*/

void	buildup_a_stack(t_list **a_stack, int ac, char **av, int i)
{
	int		j;
	int		k;
	int		l;

	k = 1;
	while (k < ac - (i - 1))
	{
		j = ft_strlen(av[ac - k]);
		while (j >= 0)
		{
			while (j > 0 && !ft_isdigit(av[ac - k][j]))
				j--;
			av[ac - k][j + 1] = 0;
			while (j > 0 && ft_isdigit(av[ac - k][j]))
				j--;
			l = 0;
			while (ft_isdigit(av[ac - k][j + 1 + l]) && av[ac - k][j + 1 + l])
				l++;
			av[ac - k][j + 1 + l] = 0;
			buildup_add_nb(a_stack, av[ac - k] + j, j);
			j--;
		}
		k++;
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
	i = 1;
	if (!ft_strcmp(av[i], "-v"))
		i++;
	a_stack = ft_lstnew(ft_strdup("a"));
	buildup_a_stack(&a_stack, ac, av, i);
	b_stack = ft_lstnew(ft_strdup("b"));
	if (!ft_strcmp(av[1], "-v"))
		elaborate(&a_stack, &b_stack, 1);
	else
		elaborate(&a_stack, &b_stack, 0);
	ft_clear(&a_stack);
	ft_clear(&b_stack);
	return (0);
}
