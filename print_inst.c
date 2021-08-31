/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:23 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 11:16:37 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_duos(t_inst *inst, t_inst *next)
{
	if ((inst->data == 1 && next && next->data == 2)
		|| (inst->data == 2 && next && next->data == 1))
		write(1, "ss\n", 3);
	if ((inst->data == 5 && next && next->data == 6)
		|| (inst->data == 6 && next && next->data == 5))
		write(1, "rr\n", 3);
	if ((inst->data == 7 && next && next->data == 8)
		|| (inst->data == 8 && next && next->data == 7))
		write(1, "rrr\n", 4);
}

void	print_inst2(t_inst *inst, t_inst *next)
{
	if (inst->data == 1)
		write(1, "sa\n", 3);
	else if (inst->data == 2)
		write(1, "sb\n", 3);
	else if (inst->data == 3)
		write(1, "pa\n", 3);
	else if (inst->data == 4)
		write(1, "pb\n", 3);
	else if (inst->data == 5)
		write(1, "ra\n", 3);
	else if (inst->data == 6)
		write(1, "rb\n", 3);
	else if (inst->data == 7)
		write(1, "rra\n", 4);
	else if (inst->data == 8)
		write(1, "rrb\n", 4);
}

void	print_inst(t_push *ps)
{
	t_inst	*inst;
	t_inst	*next;

	inst = ps->inst;
	while (inst != NULL)
	{
		next = NULL;
		if (inst->next != NULL)
			next = inst->next;
		if ((inst->data == 1 && next && next->data == 2)
			|| (inst->data == 2 && next && next->data == 1)
			|| (inst->data == 5 && next && next->data == 6)
			|| (inst->data == 6 && next && next->data == 5)
			|| (inst->data == 7 && next && next->data == 8)
			|| (inst->data == 8 && next && next->data == 7))
		{
			manage_duos(inst, next);
			inst = inst->next;
		}
		else
			print_inst2(inst, next);
		inst = inst->next;
	}
}
