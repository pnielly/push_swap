/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 17:59:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

//swap a - swap first 2 elements at top of stack a
void	sa(t_list **a, t_list **b, int print)
{
	char	*tmp;

	(void)b;
	if (print)
		ft_putstr_endl("sa");
	if (!ft_strcmp((*a)->content, "a") || !ft_strcmp((*a)->next->content, "a"))
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
}

//swap b - swap first 2 elements at top of stack b
void	sb(t_list **a, t_list **b, int print)
{
	char	*tmp;

	(void)a;
	if (print)
		ft_putstr_endl("sb");
	if (!ft_strcmp((*b)->content, "b") || !ft_strcmp((*b)->next->content, "b"))
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
}

// ss - sa and sb
void	ss(t_list **a, t_list **b, int print)
{
	if (print)
		ft_putstr_endl("ss");
	sa(a, b, 0);
	sb(a, b, 0);
}
