/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:40:25 by gasselin          #+#    #+#             */
/*   Updated: 2021/09/01 13:44:00 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	init_ps(int argc, char **argv)
{
	t_push	ps;

	ps.argc = argc;
	ps.argv = argv;
	ps.sorted = 1;
	ps.nb = 0;
	ps.count = 0;
	ps.inst = NULL;
	ps.tmp = 0;
	ps.size = 0;
	ps.sort1 = 0;
	return (ps);
}

void	modify_pile(t_push *ps)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < ps->size)
	{
		j = 0;
		count = 0;
		while (j < ps->size)
			if (ps->a.array[i] > ps->a.array[j++])
				count++;
		ps->c.array[i++] = count;
	}
	i = 0;
	while (i < ps->size)
	{
		ps->a.array[i] = ps->c.array[i];
		i++;
	}
	free (ps->c.array);
}

void	stack_size(t_push *ps)
{
	char	**tab;
	int		i;

	i = 0;
	if (ps->argc > 2)
	{
		ps->size = ps->argc - 1;
		return ;
	}
	tab = ft_split(ps->argv[1], ' ');
	if (!tab)
	{
		write(1, "Arguments split error\n", 22);
		exit(1);
	}
	while (tab[ps->size])
		ps->size++;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	check_errors(t_push *ps)
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

int	main(int argc, char **argv)
{
	t_push	ps;

	ps = init_ps(argc, argv);
	if (argc < 2)
		return (0);
	stack_size(&ps);
	if (check_errors(&ps))
		return (write(1, "Error\n", 6));
	init_stacks(&ps);
	build_pile(&ps);
	modify_pile(&ps);
	if (ps.a.size <= 5)
		sort_small(&ps);
	else if (ps.a.size <= 10)
		sort_medium(&ps);
	else
		sort_big(&ps);
	print_inst(&ps);
	ft_lstdel(&ps.inst);
	free (ps.a.array);
	free (ps.b.array);
	return (0);
}
