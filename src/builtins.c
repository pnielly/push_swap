/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:24:51 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 18:37:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
** builtins' names
*/

char	*bt_str(int i)
{
	char	*bt[BLTS + 1];

	bt[0] = "sa";
	bt[1] = "sb";
	bt[2] = "ss";
	bt[3] = "pa";
	bt[4] = "pb";
	bt[5] = "ra";
	bt[6] = "rb";
	bt[7] = "rr";
	bt[8] = "rra";
	bt[9] = "rrb";
	bt[10] = "rrr";
	bt[11] = NULL;
	return (bt[i]);
}

/*
** builtins' functions
*/

void	(*bt_ft(int i))(t_list **a, t_list **b, int print)
{
	void	(*bt_ft[BLTS + 1])(t_list **a, t_list **b, int print);

	bt_ft[0] = &sa;
	bt_ft[1] = &sb;
	bt_ft[2] = &ss;
	bt_ft[3] = &pa;
	bt_ft[4] = &pb;
	bt_ft[5] = &ra;
	bt_ft[6] = &rb;
	bt_ft[7] = &rr;
	bt_ft[8] = &rra;
	bt_ft[9] = &rrb;
	bt_ft[10] = &rrr;
	return (bt_ft[i]);
}
