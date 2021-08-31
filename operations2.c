/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:40:28 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 10:25:27 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push *ps)
{
	int	i;
	int	nb;

	i = 0;
	if (ps->a.size >= 2)
	{
		nb = ps->a.array[0];
		while (i < ps->a.size - 1)
		{
			ps->a.array[i] = ps->a.array[i + 1];
			i++;
		}
		ps->a.array[ps->a.size - 1] = nb;
		ft_add_inst(&ps->inst, 5, ps);
	}
}

void	rotate_b(t_push *ps)
{
	int	i;
	int	nb;

	i = 0;
	if (ps->b.size >= 2)
	{
		nb = ps->b.array[0];
		while (i < ps->b.size - 1)
		{
			ps->b.array[i] = ps->b.array[i + 1];
			i++;
		}
		ps->b.array[ps->b.size - 1] = nb;
		ft_add_inst(&ps->inst, 6, ps);
	}
}

void	reverse_rotate_a(t_push *ps)
{
	int	i;
	int	nb;

	i = ps->a.size - 1;
	if (ps->a.size >= 2)
	{
		nb = ps->a.array[ps->a.size - 1];
		while (i > 0)
		{
			ps->a.array[i] = ps->a.array[i - 1];
			i--;
		}
		ps->a.array[0] = nb;
		ft_add_inst(&ps->inst, 7, ps);
	}
}

void	reverse_rotate_b(t_push *ps)
{
	int	i;
	int	nb;

	i = ps->b.size - 1;
	if (ps->b.size >= 2)
	{
		nb = ps->b.array[ps->b.size - 1];
		while (i > 0)
		{
			ps->b.array[i] = ps->b.array[i - 1];
			i--;
		}
		ps->b.array[0] = nb;
		ft_add_inst(&ps->inst, 8, ps);
	}
}
