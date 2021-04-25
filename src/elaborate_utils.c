/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 20:40:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	b_is_solved(t_list *b, t_list *a)
{
	t_list	*tmp;

	tmp = b;
	while (tmp->next)
	{
		if (ft_atoi(tmp->next->content) > ft_atoi(tmp->content))
			return (0);
		tmp = tmp->next;
	}
	if (ft_lstsize(b) <= 2 && !ft_is_solved(a, 0))
		return (0);
	return (1);
}

/*
** Finds the position of the element with value min
*/
int	ft_position(t_list *a, int min)
{
	int	i;

	i = 1;
	while (a && ft_atoi(a->content) != min)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	find_min(t_list *a)
{
	int		min;

//	printf("JE SUI DANS FIND MIN\n");
	min = ft_atoi(a->content);
	while (a->next->next)
	{
		a = a->next;
		if (min > ft_atoi(a->content))
			min = ft_atoi(a->content);
	}
//	printf("JE SORDS DE  DANS FIND MIN\n");
	return (min);
}

int	find_max(t_list *a)
{
	int		max;

//	printf("JE SUI DANS FIND MIN\n");
	max = ft_atoi(a->content);
	while (a->next->next)
	{
		a = a->next;
		if (max < ft_atoi(a->content))
			max = ft_atoi(a->content);
	}
//	printf("JE SORDS DE  DANS FIND MIN\n");
	return (max);
}


/*
 ** find the n-th smallest element of the list
 */
int	find_n_min(t_list *a, int n)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	while (--n > 0)
	{
		min = find_min(tmp);
		ft_lst_rm_one(&tmp, ft_position(tmp, min));
	}
	return (find_min(tmp));
}

/*
 ** checks if the element with the value 'min'
 ** is closer to the top ('deb') or to the end ('end')
 ** --> helps decide if we will rotate or reverse_rotate
 */
char	get_dist_min(t_list *a, int min)
{
	int	deb;
	int	end;

	deb = 0;
	end = 0;
	if (ft_atoi(a->content) == min)
		return ('n');
	while (ft_atoi(a->content) != min && ft_strcmp(a->content, "a"))
	{
		a = a->next;
		deb++;
	}
	while (ft_strcmp(a->content, "a"))
	{
		a = a->next;
		end++;
	}
	if (end > deb)
		return ('d');
	return ('e');
}
