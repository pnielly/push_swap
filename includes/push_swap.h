/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:25:43 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 21:13:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BLTS 11
# define BORNE_INF 2147483648
# define BORNE_SUP 2147483647
# define SPACE " \t\n\r\v\b"
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}					t_stack;

void	elab_3(t_list **a, t_list **b, int print);
void	elab_11(t_list **a, t_list **b, int print);
void	elab_101(t_list **a, t_list **b, int print);
void	elab_500(t_list **a, t_list **b, int print);
int		exec_cmd(t_list *instr, t_list **a_stack, t_list **b, int verb);
void	ft_display(t_list *a, t_list *b);
void	print_lst(t_list *pr);
int		ft_is_solved(t_list *a, int print);
int		ft_check_for_error(int ac, char **av);
int		ft_error(char *str, char *pb);
t_list	*ft_clear(t_list **a);

/*
** Utils for elaborate (exec_cmd)
*/

int		b_is_solved(t_list *b, t_list *a);
int		find_top_next(t_list *a, int thr_inf, int thr_sup);
int		find_bot_next(t_list *a, int thr_inf, int thr_sup);
int		ft_position(t_list *a, int min);
int		find_floor_b(t_list *b, int next);
int		find_floor_a(t_list *a, int next);
int		ft_min_position(t_list *a, int min);
int		find_min(t_list *a);
int		find_max(t_list *a);
int		find_n_min(t_list *a, int n);
int		find_n_max(t_list *a, int n);
char	get_dist_min(t_list *a, int min);
int		ft_find_next(t_list *a, int min, int max);
int		ft_last_elem_value(t_list *a);

/*
** Utils for elab_100 and elab_500 (exec_cmd)
*/

void	calibrate_a(t_list **a, t_list **b, int print);
void	get_on_top_of_a(t_list **a, t_list **b, int *tab, int print);
void	fill_b(t_list **a, t_list **b, int *thr, int print);
void	order_b(t_list **b, t_list **a, int print);
int		remains_in_a(t_list *a, int thr_inf, int thr_sup);

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
