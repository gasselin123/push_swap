/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:40:02 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 10:25:10 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push *ps)
{
	int	nb;

	if (ps->a.size >= 2)
	{
		nb = ps->a.array[0];
		ps->a.array[0] = ps->a.array[1];
		ps->a.array[1] = nb;
		ft_add_inst(&ps->inst, 1, ps);
	}
}

void	swap_b(t_push *ps)
{
	int	nb;

	if (ps->b.size >= 2)
	{
		nb = ps->b.array[0];
		ps->b.array[0] = ps->b.array[1];
		ps->b.array[1] = nb;
		ft_add_inst(&ps->inst, 2, ps);
	}
}

void	push_a(t_push *ps)
{
	int	i;

	if (ps->b.size > 0)
	{
		i = ps->a.size;
		while (i > 0)
		{
			ps->a.array[i] = ps->a.array[i - 1];
			i--;
		}
		ps->a.array[0] = ps->b.array[0];
		i = 0;
		if (ps->b.size > 1)
		{
			while (i < ps->b.size - 1)
			{
				ps->b.array[i] = ps->b.array[i + 1];
				i++;
			}
		}
		ps->b.array[i] = '\0';
		ps->a.size++;
		ps->b.size--;
		ft_add_inst(&ps->inst, 3, ps);
	}
}

void	push_b(t_push *ps)
{
	int	i;

	if (ps->a.size > 0)
	{
		i = ps->b.size;
		while (i > 0)
		{
			ps->b.array[i] = ps->b.array[i - 1];
			i--;
		}
		ps->b.array[0] = ps->a.array[0];
		i = 0;
		if (ps->a.size > 1)
		{
			while (i < ps->a.size - 1)
			{
				ps->a.array[i] = ps->a.array[i + 1];
				i++;
			}
		}
		ps->a.array[i] = '\0';
		ps->a.size--;
		ps->b.size++;
		ft_add_inst(&ps->inst, 4, ps);
	}
}
