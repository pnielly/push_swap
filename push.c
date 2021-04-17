/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 17:07:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

//push a - take the first element at the top of b and put it at top of a. Nothing if b empty
void	pa(t_list **a, t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		ft_putstr_endl("pa");
	if (!b)
		return ;
	else
	{
		if (!ft_strcmp((*b)->content, "b"))
			return ;
	}
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

//push b - take the first element at the top of a and put it at top of b. Nothing if a empty
void	pb(t_list **a, t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		ft_putstr_endl("pb");
	if (!a)
		return ;
	else
	{
		if (!ft_strcmp((*a)->content, "a"))
			return ;
	}
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
