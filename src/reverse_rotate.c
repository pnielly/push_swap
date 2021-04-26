/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 19:48:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/**
** reverse rotate a - shift down a stack by 1 (last element becomes first one)
**/
void	rra(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (print)
		ft_putstr_endl("rra");
	if (!ft_strcmp((*a)->content, "a"))
		return ;
	tmp = *a;
	tmp2 = tmp->next;
	while (tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_lstswap(tmp, tmp2);
	tmp2->next = *a;
	tmp->next = NULL;
	*a = tmp2;
	(void)b;
}

/**
** reverse rotate b - shift down b stack by 1 (last element becomes first one)
**/
void	rrb(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (print)
		ft_putstr_endl("rrb");
	if (!ft_strcmp((*b)->content, "b"))
		return ;
	tmp = *b;
	tmp2 = tmp->next;
	while (tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_lstswap(tmp, tmp2);
	tmp2->next = *b;
	tmp->next = NULL;
	*b = tmp2;
	(void)a;
}

/**
** rrr - rra and rrb at the same time
**/
void	rrr(t_list **a, t_list **b, int print)
{
	if (print)
		ft_putstr_endl("rrr");
	rra(a, b, 0);
	rrb(a, b, 0);
}
