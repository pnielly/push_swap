/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/25 15:42:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_top_next(t_list *a, int thr_inf, int thr_sup)
{
	while (ft_strcmp(a->content, "a") && (ft_atoi(a->content) > thr_sup || ft_atoi(a->content) < thr_inf))
		a = a->next;
//	printf("sortie de find_top = %d\n", ft_atoi(a->content));
	return (ft_atoi(a->content));
}

int	find_bot_next(t_list *a, int thr_inf, int thr_sup)
{
	int	bot_next;
	
	while (ft_strcmp(a->content, "a"))
	{
		if (ft_atoi(a->content) <= thr_sup && ft_atoi(a->content) >= thr_inf)
			bot_next = ft_atoi(a->content);
		a = a->next;
	}
//	printf("sortie de find_bot = %d\n", bot_next);
	return (bot_next);
}
