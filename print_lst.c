/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:36:26 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 18:04:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_lst(t_list *pr)
{
	t_list	*tmp;

	tmp = pr;
	while (tmp)
	{
		ft_putstr_endl(tmp->content);
		tmp = tmp->next;
	}
}

void	ft_display(t_list *a, t_list *b)
{
	t_list	*tmp;
	size_t	size_a;
	size_t	size_b;
	size_t	size;
	size_t	len_a;
	size_t	len_b;
	size_t	len;
	size_t	diff;

	size_a = 0;
	size_b = 0;
	len_a = 0;
	len_b = 0;
	tmp = a;
	while (tmp->next)
	{
		len_a = ft_max(ft_strlen(tmp->content), len_a);
		tmp = tmp->next;
		size_a++;
	}
	tmp = b;
	while (tmp->next)
	{
		len_b = ft_max(ft_strlen(tmp->content), len_b);
		tmp = tmp->next;
		size_b++;
	}
	len = ft_max(len_a, len_b);
	size = ft_max(size_a, size_b);
	while (size--)
	{
		len_a = len;
		if (!a || !ft_strcmp(a->content, "a"))
		{
			while (len_a--)
				ft_putstr(" ");
		}
		else
		{
			ft_putstr(a->content);
			diff = len - ft_strlen(a->content);
			while (diff--)
				ft_putstr(" ");
			a = a->next;
		}
		ft_putstr("||");
		len_b = len;
		if (!b || !ft_strcmp(b->content, "b"))
		{
			while (len_b--)
				ft_putstr(" ");
			ft_putstr_endl("");
		}
		else
		{
			ft_putstr_endl(b->content);
			b = b->next;
		}
	}
	ft_putstr("_");
	len_a = len + 1;
	while (len_a--)
		ft_putstr(" ");
	ft_putstr_endl("_");
	ft_putstr("a");
	len_a = len + 1;
	while (len_a--)
		ft_putstr(" ");
	ft_putstr_endl("b");
	ft_putstr_endl("--------------------------------");
}
