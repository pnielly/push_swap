/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 12:32:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
** Finds the position of the element with value min
*/
int	ft_position(t_list *a, int min)
{
	int	i;

	i = 1;
	if (ft_lstsize(a) <= 1)
		return (0);
	while (a && ft_atoi(a->content) != min)
	{
		i++;
		a = a->next;
	}
	return (i);
}

/*
 ** Find the element of the list with the min int value
 */
int	find_min(t_list *a)
{
	int		min;

	if (ft_lstsize(a) <= 2)
		return (ft_atoi(a->content));
	min = ft_atoi(a->content);
	while (ft_strcmp(a->next->content, "a") && ft_strcmp(a->next->content, "b"))
	{
		a = a->next;
		if (min > ft_atoi(a->content))
			min = ft_atoi(a->content);
	}
	return (min);
}

/*
 ** Find the element of the list with the max int value
 */
int	find_max(t_list *a)
{
	int		max;

	max = ft_atoi(a->content);
	while (ft_strcmp(a->content, "a") && ft_strcmp(a->content, "b"))
	{
		a = a->next;
		if (max < ft_atoi(a->content))
			max = ft_atoi(a->content);
	}
	return (max);
}

/*
 ** Find the n-th smallest element of the list
 */
int	find_n_min(t_list *a, int n)
{
	int		min;
	t_list	*tmp;

	if (n > ft_lstsize(a))
		return (0);
	ft_lstcopy(&a, &tmp);
	while (--n > 0)
	{
		min = find_min(tmp);
		ft_lst_rm_one(&tmp, ft_position(tmp, min));
	}
	min = find_min(tmp);
	ft_clear(&tmp);
	return (min);
}

/*
 ** find the n-th biggest element of the list
 */
int	find_n_max(t_list *a, int n)
{
	int		max;
	t_list	*tmp;

	if (n > ft_lstsize(a))
		return (0);
	ft_lstcopy(&a, &tmp);
	while (--n > 0)
	{
		max = find_max(tmp);
		ft_lst_rm_one(&tmp, ft_position(tmp, max));
	}
	max = find_max(tmp);
	ft_clear(&tmp);
	return (max);
}
