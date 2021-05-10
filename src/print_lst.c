/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:36:26 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 14:12:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*
** Note : these 2 functions helped to the elaboration
** of the program, but are not used in the final product.
*/

void	ft_lst_size(t_list *a, t_list *b)
{
	int		size_a;
	int		size_b;
	t_list	*tmp;

	size_a = 0;
	size_b = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		size_a++;
	}
	tmp = b;
	while (tmp)
	{
		tmp = tmp->next;
		size_b++;
	}
	ft_putstr("size of a is :");
	ft_putstr_endl(ft_itoa(size_a));
	ft_putstr("size of b is :");
	ft_putstr_endl(ft_itoa(size_b));
}

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
