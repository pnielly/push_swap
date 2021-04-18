/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:46:31 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 23:14:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
** Get the instructions from input (put there by push_swap)
*/

t_list	*get_instr(void)
{
	t_list	*tmp;
	char	*line;
	t_list	*instr;

	instr = ft_lstnew("Instructions");
	tmp = instr;
	while (get_next_line(0, &line))
	{
		tmp->next = ft_lstnew(line);
		tmp = tmp->next;
	}
	tmp = instr;
	while (tmp)
		tmp = tmp->next;
	return (instr);
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
	t_list	*tmp;
	t_list	*instr;

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
	instr = get_instr();
	exec_cmd(instr, &a_stack, &b_stack);
	return (0);
}
