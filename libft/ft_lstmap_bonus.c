/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:50:49 by pnielly           #+#    #+#             */
/*   Updated: 2021/04/03 19:55:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	**l1;
	t_list	*tmp1;

	tmp = lst;
	if (!(l1 = malloc(sizeof(t_list) * ft_lstsize(lst))))
		return (NULL);
	tmp1 = *l1;
	while (tmp->next)
	{
		tmp1 = tmp;
		tmp1 = tmp1->next;
	}
	del(tmp->next);
	ft_lstiter(*l1, (void *)f);
	return (*l1);
}
