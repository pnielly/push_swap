/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:46:31 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 23:49:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
 ** Adding new number to "a stack"
 */

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
			while (j > 0 && ft_issdigit(av[ac - k][j], av[ac - k][j + 1]))
				j--;
			l = 0;
			while (ft_issdigit(av[ac - k][j + 1 + l], av[ac - k][j + 2 + l])
					&& av[ac - k][j + 1 + l])
				l++;
			av[ac - k][j + 1 + l] = 0;
			buildup_add_nb(a_stack, av[ac - k] + j, j);
			j--;
		}
		k++;
	}
}

/**
 ** Les éléments "a" et "b" représentent la fin 
 ** de leurs listes chaînées respectives.
 ** Autrement dit : Si (*a_stack)->content = "a", 
 ** la liste est considérée comme vide. 
 ** Idem pour b_stack.
 **
 ** Cela évite de devoir free et malloc les listes 
 ** à chaque fois qu'elles sont vides.
 **/

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		i;

	if (ft_check_for_error(ac, av))
		return (0);
	i = 1;
	if (!ft_strcmp(av[i], "-v"))
		i++;
	a_stack = ft_lstnew(ft_strdup("a"));
	buildup_a_stack(&a_stack, ac, av, i);
	if (check_duplicates(a_stack))
	{
		ft_clear(&a_stack);
		return (ft_error("Duplicates ! ", ""));
	}
	b_stack = ft_lstnew(ft_strdup("b"));
	if (!ft_strcmp(av[1], "-v"))
		return (get_instr(&a_stack, &b_stack, 1));
	else
		return (get_instr(&a_stack, &b_stack, 0));
}
