/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:55:06 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/27 11:09:10 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack *from, t_stack *to)
{
	int	i;

	if (from->size > 0)
	{
		i = to->size;
		while (i > 0)
		{
			to->array[i] = to->array[i - 1];
			i--;
		}
		to->array[0] = from->array[0];
		i = 0;
		if (from->size > 1)
		{
			while (i < from->size - 1)
			{
				from->array[i] = from->array[i + 1];
				i++;
			}
		}
		from->array[i] = '\0';
		to->size++;
		from->size--;
	}
}

void	rotate(t_stack *stack)
{
	int	i;
	int	nb;

	i = 0;
	if (stack->size >= 2)
	{
		nb = stack->array[0];
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->size - 1] = nb;
	}
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	nb;

	i = stack->size - 1;
	if (stack->size >= 2)
	{
		nb = stack->array[stack->size - 1];
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = nb;
	}
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = tmp;
	}
}

int	check_errors(t_checker *ps)
{
	int	count;
	int	i;

	if (ps->argc == 2)
	{
		count = ft_count_char(ps->argv[1], " -0123456789");
		if ((size_t)count != ft_strlen(ps->argv[1]))
			return (1);
	}
	else
	{
		i = 1;
		while (i < ps->argc)
		{
			count = ft_count_char(ps->argv[i], "-0123456789");
			if ((size_t)count != ft_strlen(ps->argv[i++]))
				return (1);
		}
	}
	return (0);
}
