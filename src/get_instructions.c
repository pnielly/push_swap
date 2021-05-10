/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:45:24 by user42            #+#    #+#             */
/*   Updated: 2021/05/11 01:01:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	exec_cmd(char *line, t_list **a, t_list **b, int verb)
{
	int	i;

	i = 0;
	while (i < BLTS && ft_strcmp(line, bt_str(i)))
		i++;
	if (i < BLTS)
	{
		(*bt_ft(i))(a, b, 0);
		if (verb)
			ft_display(*a, *b);
	}
	else
	{
		ft_clear(a);
		ft_clear(b);
		return (ft_error("Wrong command !", ""));
	}
	return (0);
}

int	read_instr(int verb, t_list **a, t_list **b, int ret)
{
	char	line[4];
	char	buf[2];
	int		i;

	buf[1] = 0;
	while (1)
	{
		++ret;
		i = read(0, &buf, 1);
		if (i <= 0)
			break ;
		if (buf[0] && buf[0] != '\n')
			line[ret] = buf[0];
		else
		{
			line[ret] = 0;
			ret = -1;
			if (exec_cmd(line, a, b, verb))
				return (1);
		}
	}
	return (0);
}

/*
 ** Get the instructions from input (put there by push_swap normally)
 */

int	get_instr(t_list **a, t_list **b, int verb)
{
	if (read_instr(verb, a, b, -1))
	{
		ft_clear(a);
		ft_clear(b);
		return (1);
	}
	else
	{
		ft_is_solved(*a, 1);
		ft_clear(a);
		ft_clear(b);
	}
	return (0);
}
