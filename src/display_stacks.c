/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:42:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 19:42:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	get_size_table(t_list *a, t_list *b)
{
	t_list	*tmp;
	size_t	size_a;
	size_t	size_b;

	size_a = 0;
	size_b = 0;
	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
		size_a++;
	}
	tmp = b;
	while (tmp->next)
	{
		tmp = tmp->next;
		size_b++;
	}
	return (ft_max(size_a, size_b));
}

int	get_len_table(t_list *a, t_list *b)
{
	t_list	*tmp;
	size_t	len_a;
	size_t	len_b;

	len_a = 0;
	len_b = 0;
	tmp = a;
	while (tmp->next)
	{
		len_a = ft_max(ft_strlen(tmp->content), len_a);
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp->next)
	{
		len_b = ft_max(ft_strlen(tmp->content), len_b);
		tmp = tmp->next;
	}
	return (ft_max(len_a, len_b));
}

void	end_of_table(int tmp, int len)
{
	ft_putstr("_");
	tmp = len + 1;
	while (tmp--)
		ft_putstr(" ");
	ft_putstr_endl("_");
	ft_putstr("a");
	tmp = len + 1;
	while (tmp--)
		ft_putstr(" ");
	ft_putstr_endl("b");
	ft_putstr_endl("--------------------------------");
}

void	end_of_line(t_list *a, size_t tmp, char stack)
{
	if (stack == 'c')
	{
		while (tmp--)
			ft_putstr(" ");
	}
	if (!a || !ft_strcmp(a->content, "a") || !ft_strcmp(a->content, "b"))
	{
		while (tmp--)
			ft_putstr(" ");
		if (stack == 'b')
			ft_putstr_endl("");
	}
}

void	ft_display(t_list *a, t_list *b)
{
	size_t	size;
	size_t	len;
	size_t	diff;

	len = get_len_table(a, b);
	size = get_size_table(a, b);
	while (size--)
	{
		end_of_line(a, len, 'a');
		if (a && ft_strcmp(a->content, "a"))
		{
			ft_putstr(a->content);
			diff = len - ft_strlen(a->content);
			end_of_line(a, diff, 'c');
			a = a->next;
		}
		ft_putstr("||");
		end_of_line(b, len, 'b');
		if (b && ft_strcmp(b->content, "b"))
		{
			ft_putstr_endl(b->content);
			b = b->next;
		}
	}
	end_of_table(len, len);
}
