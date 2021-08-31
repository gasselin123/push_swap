/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:38:42 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 11:22:42 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_stack s)
{
	int	i;
	int	nb;
	int	sorted;

	i = 1;
	sorted = 1;
	nb = s.array[0];
	while (i < s.size)
	{
		if (nb > s.array[i])
		{
			sorted = 0;
			break ;
		}
		nb = s.array[i];
		i++;
	}
	return (sorted);
}

int	check_duplicates(t_checker *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->a.size)
	{
		j = i + 1;
		while (j < ps->a.size)
		{
			if (ps->a.array[i] == ps->a.array[j])
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	error_atoi(t_checker *ps)
{
	free (ps->a.array);
	free (ps->b.array);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi_ps(char *s, t_checker *ps)
{
	long	result;
	int		minus;

	result = 0;
	minus = 1;
	while ((s[0] >= 9 && s[0] <= 13) || s[0] == 32)
		s++;
	if (s[0] == '-')
		minus = minus * -1;
	if (s[0] == '-' || s[0] == '+')
		s++;
	while (s[0] >= '0' && s[0] <= '9')
	{
		result = (result * 10) + s[0] - '0';
		s++;
		if (result * minus > 2147483647 || result * minus < -2147483648)
			error_atoi(ps);
	}
	return (result * minus);
}

void	init_stacks(t_checker *ps)
{
	ps->a.size = ps->size;
	ps->b.size = 0;
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
}
