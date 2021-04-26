/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 20:11:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
**rotate a - shift up a stack by 1 (first element becomes last)
** tmp2 is used to swap the last 2 elements so that "a" remains the last element.
*/
void	ra(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	char	*tmp2;

	if (print)
		ft_putstr_endl("ra");
	if (!ft_strcmp((*a)->content, "a"))
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*a);
	tmp2 = (*a)->content;
	(*a)->content = tmp->content;
	tmp->content = tmp2;
	tmp = (*a)->next;
	(*a)->next = NULL;
	*a = tmp;
	(void)b;
}

/*
**rotate b - shift up b stack by 1 (first element becomes last)
*/
void	rb(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	char	*tmp2;

	if (print)
		ft_putstr_endl("rb");
	if (!ft_strcmp((*b)->content, "b"))
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*b);
	tmp2 = (*b)->content;
	(*b)->content = tmp->content;
	tmp->content = tmp2;
	tmp = (*b)->next;
	(*b)->next = NULL;
	*b = tmp;
	(void)a;
}

/*
** rr - ra and rb at the same time
*/
void	rr(t_list **a, t_list **b, int print)
{
	if (print)
		ft_putstr_endl("rr");
	ra(a, b, 0);
	rb(a, b, 0);
}
