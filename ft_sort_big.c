/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:10:52 by gasselin          #+#    #+#             */
/*   Updated: 2021/09/01 15:02:10 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_push *ps, int mid)
{
	int	top;
	int	bot;

	while (ps->b.size > 0)
	{
		bot = -1;
		top = ps->b.size;
		while (++bot < ps->b.size)
			if (is_min(ps->b, ps->b.array[ps->b.size - 1 - bot])
				|| is_max(ps->b, ps->b.array[ps->b.size - 1 - bot]))
				break ;
		while (--top > 0)
			if (is_min(ps->b, ps->b.array[ps->b.size - 1 - top])
				|| is_max(ps->b, ps->b.array[ps->b.size - 1 - top]))
				break ;
		rotate_to_top_bot(ps, top, bot);
	}
	while (ps->a.array[0] < mid)
		rotate_a(ps);
}

void	divide_b(t_push *ps, int b_size)
{
	int	mid;
	int	i;

	mid = find_median(ps->b, ps->b.size);
	while (is_any_over(ps->b, ps->b.size, mid))
	{
		if (ps->b.array[0] < mid)
			rotate_b(ps);
		else
			push_a(ps);
	}
	i = ps->b.size;
	if (ps->b.size > 50)
		divide_b(ps, ps->b.size);
	else
		sort_b(ps, ps->a.array[0]);
	if (ps->b.size == 0)
		while (b_size > i++)
			push_b(ps);
	if (ps->b.size > 50)
		divide_b(ps, ps->b.size);
	else
		sort_b(ps, ps->a.array[0]);
}

void	push_high(t_push *ps, int size, int mid)
{
	int	mid2;
	int	i;

	i = 0;
	mid2 = find_median(ps->a, size);
	while (is_any_lower(ps->a, size, mid2))
	{
		if (ps->a.array[0] >= mid2)
			rotate_a(ps);
		else if (ps->a.array[0] < mid2 && ps->a.array[0] >= mid)
			push_b(ps);
		size--;
	}
}

void	divide_a(t_push *ps, int size)
{
	int	mid;

	mid = find_median(ps->a, size);
	while (is_any_lower(ps->a, ps->a.size, mid))
	{
		if (ps->a.array[0] >= mid)
			rotate_a(ps);
		else
			push_b(ps);
	}
	divide_b(ps, ps->b.size);
}

void	sort_big(t_push *ps)
{
	int	mid;

	mid = find_median(ps->a, ps->a.size);
	divide_a(ps, ps->a.size);
	push_high(ps, ps->a.size / 2 + 1, mid);
	while (ps->a.array[ps->a.size - 1] > mid)
		reverse_rotate_a(ps);
	divide_b(ps, ps->b.size);
	while (ps->a.array[0] > mid)
		push_b(ps);
	divide_b(ps, ps->b.size);
	while (ps->a.array[0] >= mid)
		rotate_a(ps);
}
