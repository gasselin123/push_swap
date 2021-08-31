/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:47:03 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/31 14:00:26 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

typedef struct s_checker
{
	t_stack			a;
	t_stack			b;
	int				argc;
	char			**argv;
	int				size;
}					t_checker;

void	init_stacks(t_checker *ps);
void	build_pile(t_checker *ps);
int		ft_atoi_ps(char *s, t_checker *ps);
int		check_duplicates(t_checker *ps);
int		is_sorted(t_stack s);
int		check_errors(t_checker *ps);
void	error_atoi(t_checker *ps);
int		ft_strcmp(char *s1, char *s2);

void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);

#endif