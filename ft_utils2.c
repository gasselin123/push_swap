/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:08:49 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/24 11:24:53 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack s)
{
	int	max;
	int	i;

	max = s.array[0];
	i = 1;
	while (i < s.size)
	{
		if (max < s.array[i])
			max = s.array[i];
		i++;
	}
	return (max);
}

int	find_min(t_stack s)
{
	int	min;
	int	i;

	min = s.array[0];
	i = 1;
	while (i < s.size)
	{
		if (min > s.array[i])
			min = s.array[i];
		i++;
	}
	return (min);
}

int	find_nb(t_stack s, int nb)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		if (s.array[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

int	is_any_lower(t_stack s, int size, int nb)
{
	int	i;

	i = 0;
	while (size-- > 0)
		if (s.array[i++] < nb)
			return (1);
	return (0);
}

int	is_any_over(t_stack s, int size, int nb)
{
	int	i;

	i = 0;
	while (size-- > 0)
		if (s.array[i++] >= nb)
			return (1);
	return (0);
}
