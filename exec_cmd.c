/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:12:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 23:14:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_lst_size(t_list *a, t_list *b)
{
	int	size_a;
	int	size_b;
	t_list	*tmp;

	size_a = 0;
	size_b = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		size_a++;
	}
	tmp = b;
	while (tmp)
	{
		tmp = tmp->next;
		size_b++;
	}
	ft_putstr("size of a is :");
	ft_putstr_endl(ft_itoa(size_a));
	ft_putstr("size of b is :");
	ft_putstr_endl(ft_itoa(size_b));
}

int	exec_cmd(t_list *instr, t_list **a, t_list **b)
{
	int	i;

	instr = instr->next;
	while (instr)
	{
		i = 0;
		while (i < BLTS && ft_strcmp(instr->content, bt_str(i)))
			i++;
		if (i < BLTS)
			(*bt_ft(i))(a, b, 0);
		else
			return (ft_error("This command is not allowed or incorrectly formatted : ", (char *)instr->content));
		instr = instr->next;
	}
	ft_is_solved(*a, 1);
	return (0);
}
