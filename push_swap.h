/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:25:43 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 20:19:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define BLTS 11
#include "libft/libft.h"
#include <stdio.h>

typedef	struct		s_stack
{
	void	*content;
	struct s_stack	*next;
}		t_stack;

int	exec_cmd(t_list *instr, t_list **a_stack, t_list **b);
void	ft_display(t_list *a, t_list *b);
void	print_lst(t_list *pr);
int	ft_is_solved(t_list *a, int print);
int	ft_check_for_error(int ac, char **av);
int	ft_error(char *str, char *pb);

/*
** Functions pointers
*/

char	*bt_str(int i);
void	(*bt_ft(int i))(t_list **a, t_list **b, int print);

/*
** CMDS
*/

void	sa(t_list **a, t_list **b, int print);
void	sb(t_list **a, t_list **b, int print);
void	ss(t_list **a, t_list **b, int print);
void	pa(t_list **a, t_list **b, int print);
void	pb(t_list **a, t_list **b, int print);
void	ra(t_list **a, t_list **b, int print);
void	rb(t_list **a, t_list **b, int print);
void	rr(t_list **a, t_list **b, int print);
void	rra(t_list **a, t_list **b, int print);
void	rrb(t_list **a, t_list **b, int print);
void	rrr(t_list **a, t_list **b, int print);

#endif
