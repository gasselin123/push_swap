/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:52:39 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 11:20:44 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(t_stack s, int nb)
{
	int	i;

	i = 0;
	while (i < s.size)
		if (nb > s.array[i++])
			return (0);
	return (1);
}

int	is_max(t_stack s, int nb)
{
	int	i;

	i = 0;
	while (i < s.size)
		if (nb < s.array[i++])
			return (0);
	return (1);
}
