/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:56:46 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 11:19:53 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_push *ps)
{
	ps->a.size = ps->size;
	ps->b.size = 0;
	ps->c.size = ps->size;
	ps->a.array = malloc(sizeof(int) * ps->size);
	if (!ps->a.array)
	{
		write(1, "Memory allocation error\n", 24);
		exit(1);
	}
	ps->b.array = malloc(sizeof(int) * ps->size);
	if (!ps->b.array)
	{
		free (ps->a.array);
		write(1, "Memory allocation error\n", 24);
		exit(1);
	}
	ps->c.array = malloc(sizeof(int) * ps->size);
	if (!ps->b.array)
	{
		free (ps->a.array);
		free (ps->b.array);
		write(1, "Memory allocation error\n", 24);
		exit(1);
	}
}
