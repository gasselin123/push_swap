/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:36:16 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/31 13:11:59 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_next_number(char *str, int j)
{
	while (str[j] == ' ' && str[j] != '\0')
		j++;
	while (((str[j] >= 48 && str[j] <= 57) || str[j] == 45) && str[j] != '\0')
		j++;
	return (j);
}

char	*ft_find_number(char *str, int j)
{
	int		i;
	int		k;
	char	*s;

	i = 0;
	while (str[j] == ' ' && str[j] != '\0')
		j++;
	k = j;
	while (((str[j] >= 48 && str[j] <= 57) || str[j] == 45) && str[j] != '\0')
		j++;
	s = ft_substr(str, k, j - k);
	return (s);
}

void	ft_fill_tab(t_push *ps)
{
	int		i;
	int		j;
	char	*arg;

	i = 0;
	j = 0;
	while (i < ps->size)
	{
		arg = ft_find_number(ps->argv[1], j);
		j = ft_next_number(ps->argv[1], j);
		ps->a.array[i] = ft_atoi_ps(arg, ps);
		free (arg);
		i++;
	}
}

void	build_pile(t_push *ps)
{
	int		i;

	i = 1;
	while (i < ps->argc)
		if (ps->argv[i++][0] == '\0')
			error_atoi(ps);
	i = 1;
	if (ps->argc > 2)
	{
		while (i < ps->argc)
		{
			ps->a.array[i - 1] = ft_atoi_ps(ps->argv[i], ps);
			i++;
		}
	}
	else
		ft_fill_tab(ps);
	if (is_sorted(ps->a) || check_duplicates(ps))
	{
		free (ps->a.array);
		free (ps->b.array);
		free (ps->c.array);
		exit(0);
	}
}
