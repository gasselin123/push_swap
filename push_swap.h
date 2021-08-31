/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:40:09 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/31 11:09:05 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"

typedef struct s_inst
{
	struct s_inst	*next;
	int				data;
}					t_inst;

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

typedef struct s_push
{
	t_stack			a;
	t_stack			b;
	t_stack			c;
	struct s_inst	*inst;
	int				argc;
	char			**argv;
	int				sorted;
	int				nb;
	int				count;
	int				tmp;
	int				tmp2;
	int				i;
	int				pos;
	int				len_in;
	int				len_out;
	int				size;
	int				mid;
	int				sort1;
}					t_push;

int		ft_atoi_ps(char *s, t_push *ps);
int		check_duplicates(t_push *ps);
void	build_pile(t_push *ps);
void	build_pile_str(t_push *ps);
void	init_stacks(t_push *ps);
int		is_sorted(t_stack s);
void	error_atoi(t_push *ps);

void	sort_small(t_push *ps);
void	sort_medium(t_push *ps);
void	sort_big(t_push *ps);

int		find_max(t_stack s);
int		find_min(t_stack s);
int		find_nb(t_stack s, int nb);
int		find_median(t_stack s, int size);
int		is_any_lower(t_stack s, int size, int mid);
int		is_any_over(t_stack s, int size, int mid);
int		is_min(t_stack s, int nb);
int		is_max(t_stack s, int nb);
void	rotate_to_top_bot(t_push *ps, int top, int bot);

void	ft_add_inst(t_inst **inst, int n, t_push *ps);
void	print_inst(t_push *ps);

void	ft_lstdel(t_inst **list);
void	ft_lstaddback(t_inst **alst, t_inst *new);
t_inst	*ft_lst_last(t_inst *lst);

void	swap_a(t_push *ps);
void	swap_b(t_push *ps);
void	push_a(t_push *ps);
void	push_b(t_push *ps);
void	rotate_a(t_push *ps);
void	rotate_b(t_push *ps);
void	reverse_rotate_a(t_push *ps);
void	reverse_rotate_b(t_push *ps);

#endif