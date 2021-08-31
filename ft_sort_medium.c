/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 10:10:27 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/26 11:15:58 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top_bot(t_push *ps, int top, int bot)
{
	if (bot >= (ps->b.size - top - 1))
		while (top++ < ps->b.size - 1)
			rotate_b(ps);
	else
		while (bot-- >= 0)
			reverse_rotate_b(ps);
	push_a(ps);
	if (is_min(ps->b, ps->a.array[0]))
		rotate_a(ps);
}

void	push_b_medium(t_push *ps, int i)
{
	if (i < ps->a.size / 2)
		while (i--)
			rotate_a(ps);
	else
	{
		i = ps->a.size - i;
		while (i--)
			reverse_rotate_a(ps);
	}
	push_b(ps);
}

void	sort_medium(t_push *ps)
{
	int	nb;

	nb = 0;
	while (is_any_lower(ps->a, ps->a.size, 5))
	{
		if (ps->a.array[0] >= 5)
			rotate_a(ps);
		else
			push_b(ps);
	}
	if (ps->a.size >= 2 && !is_sorted(ps->a))
		sort_small(ps);
	while (ps->b.size)
		push_a(ps);
	if (!is_sorted(ps->a))
		while (ps->b.size != 3)
			push_b_medium(ps, find_nb(ps->a, nb++));
	while (ps->a.array[ps->a.size - 1] < 5)
		reverse_rotate_a(ps);
	if (ps->a.array[0] == 4)
		swap_a(ps);
	while (ps->b.size)
		push_a(ps);
}
