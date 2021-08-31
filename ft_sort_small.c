/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:03:03 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/26 10:18:45 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_push *ps)
{
	int	max;

	max = find_max(ps->a);
	if (ps->a.array[0] == max)
		rotate_a(ps);
	else if (ps->a.array[1] == max)
		reverse_rotate_a(ps);
	if (!is_sorted(ps->a))
		swap_a(ps);
}

void	sort_4_5(t_push *ps)
{
	int	nb;
	int	i;

	i = 0;
	nb = find_min(ps->a);
	while (ps->a.size > 3)
	{
		if (ps->a.array[0] == nb)
		{
			push_b(ps);
			nb++;
			i++;
			if (i == 2)
				break ;
			continue ;
		}
		if (find_nb(ps->a, nb) <= ps->a.size / 2)
			rotate_a(ps);
		else
			reverse_rotate_a(ps);
	}
	sort_3(ps);
	while (ps->b.size > 0)
		push_a(ps);
}

void	sort_small(t_push *ps)
{
	if (ps->a.size == 2)
		swap_a(ps);
	else if (ps->a.size == 3)
		sort_3(ps);
	else
		sort_4_5(ps);
}
