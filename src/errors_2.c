/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:34:32 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 21:23:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	check_duplicates(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		check;
	int		curr;

	tmp = a;
	tmp2 = tmp;
	while (ft_strcmp(tmp2->content, "a"))
	{
		tmp = tmp2;
		check = ft_atoi(tmp->content);
		while (ft_strcmp(tmp->next->content, "a"))
		{
			tmp = tmp->next;
			curr = ft_atoi(tmp->content);
			if (check == curr)
				return (1);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}
