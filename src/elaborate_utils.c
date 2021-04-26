/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaborate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 11:46:12 by user42           ###   ########.fr       */
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
//	if (ft_lstsize(b) <= 2 && !ft_is_solved(a, 0))
//		return (0);
	(void)a;
	return (1);
}

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
//	ft_putstr("find max debut\n");
	max = ft_atoi(a->content);
//	ft_putstr("find max if\n");
	while (ft_strcmp(a->content, "a") && ft_strcmp(a->content, "b"))
	{
//	ft_putstr("find max boucle\n");
		a = a->next;
		if (max < ft_atoi(a->content))
			max = ft_atoi(a->content);
	}
//	ft_putstr("find max fin\n");
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

	if (n > ft_lstsize(a))
		return (0);
	ft_lstcopy(&a, &tmp);
	while (--n > 0)
	{
		min = find_min(tmp);
		ft_lst_rm_one(&tmp, ft_position(tmp, min));
//		ft_display(a, tmp);
//		printf("size of tmp = %d et min = %d\n", ft_lstsize(tmp), find_min(tmp));
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
//	ft_putstr("JOJOOOOOO n = ");
//	ft_putstr_endl(ft_itoa(n));
		max = find_max(tmp);
		ft_lst_rm_one(&tmp, ft_position(tmp, max));
//		ft_display(a, tmp);
//		printf("size of tmp = %d et min = %d\n", ft_lstsize(tmp), find_min(tmp));
	}
//	ft_putstr("prout\n");
	if (tmp)
	{
//	ft_putstr("tmp exist !\n");
		max = find_max(tmp);
	}
	else
	{
//	ft_putstr("tmp exist PAS!\n");
		max = 0;
	}
//	ft_putstr("lolo\n");
	ft_clear(&tmp);
	return (max);
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
