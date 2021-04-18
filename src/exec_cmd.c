/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:12:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 23:14:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

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
			return (ft_error("This command is not allowed \
			or incorrectly formatted : ", (char *)instr->content));
		instr = instr->next;
	}
	ft_is_solved(*a, 1);
	ft_clear(a);
	ft_clear(&instr);
	ft_clear(b);
	return (0);
}
