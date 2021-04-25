/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 20:53:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_top_next(t_list *a, int thr)
{
	while (ft_strcmp(a->content, "a") && ft_atoi(a->content) > thr)
		a = a->next;
	return (ft_atoi(a->content));
}

int	find_bot_next(t_list *a, int thr)
{
	int	bot_next;
	
	while (ft_strcmp(a->content, "a"))
	{
		if (ft_atoi(a->content) <= thr)
			bot_next = ft_atoi(a->content);
		a = a->next;
	}
	return (bot_next);
}
