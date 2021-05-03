/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:12:46 by user42            #+#    #+#             */
/*   Updated: 2021/05/03 16:40:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	exec_cmd_2(t_list *instr, t_list **a, t_list **b, int verb)
{
	int	i;

	while (instr)
	{
		i = 0;
		while (i < BLTS && ft_strcmp(instr->content, bt_str(i)))
			i++;
		if (i < BLTS)
		{
			(*bt_ft(i))(a, b, 0);
			if (verb)
				ft_display(*a, *b);
		}
		else
			return (0);
		instr = instr->next;
	}
	return (1);
}

int	exec_cmd(t_list *instr, t_list **a, t_list **b, int verb)
{
	int	no_err;

	no_err = 0;
	if (instr)
	{
		no_err = 1;
		instr = instr->next;
	}
	if (!exec_cmd_2(instr, a, b, verb))
		return (ft_error("This command is not allowed \
		or incorrectly formatted : ", (char *)instr->content));
	if (no_err)
	{
		ft_is_solved(*a, 1);
		ft_clear(&instr);
	}
	ft_clear(a);
	ft_clear(b);
	return (0);
}
