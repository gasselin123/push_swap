/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pile_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:44:34 by gasselin          #+#    #+#             */
/*   Updated: 2021/09/02 14:22:19 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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

void	ft_fill_tab(t_checker *ps)
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

void	build_pile(t_checker *ps)
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
	if (check_duplicates(ps))
	{
		free (ps->a.array);
		free (ps->b.array);
		exit(0);
	}
}
