/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:46:38 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/31 15:12:34 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_size(t_checker *ps)
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
		ps->size = -1;
		return ;
	}
	while (tab[ps->size])
		ps->size++;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	action2(t_checker *ps, char *buf)
{
	if (ft_strcmp(buf, "rrr") == 0)
	{
		reverse_rotate(&ps->a);
		reverse_rotate(&ps->b);
	}
	else if (ft_strcmp(buf, "rr") == 0)
	{
		rotate(&ps->a);
		rotate(&ps->b);
	}
	else
	{
		free(ps->a.array);
		free(ps->b.array);
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	action(t_checker *ps, char *buf)
{
	if (ft_strcmp(buf, "sa") == 0)
		swap(&ps->a);
	else if (ft_strcmp(buf, "sb") == 0)
		swap(&ps->b);
	else if (ft_strcmp(buf, "pa") == 0)
		push(&ps->b, &ps->a);
	else if (ft_strcmp(buf, "pb") == 0)
		push(&ps->a, &ps->b);
	else if (ft_strcmp(buf, "ra") == 0)
		rotate(&ps->a);
	else if (ft_strcmp(buf, "rb") == 0)
		rotate(&ps->b);
	else if (ft_strcmp(buf, "rra") == 0)
		reverse_rotate(&ps->a);
	else if (ft_strcmp(buf, "rrb") == 0)
		reverse_rotate(&ps->b);
	else if (ft_strcmp(buf, "ss") == 0)
	{
		swap(&ps->a);
		swap(&ps->b);
	}
	else
		action2(ps, buf);
}

void	check(t_checker *ps)
{
	char	buf[4];
	int		ret;
	int		i;
	char	c;

	buf[3] = '\0';
	i = 0;
	ret = 0;
	c = 0;
	while (1)
	{
		ret = read(0, &c, 1);
		if (!ret)
			break ;
		if (c == '\n')
			buf[i++] = '\0';
		else
			buf[i++] = c;
		if (c == '\n' || i == 4)
		{
			action(ps, buf);
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	t_checker	ps;

	if (argc < 2)
		return (0);
	ps.argc = argc;
	ps.argv = argv;
	stack_size(&ps);
	if (check_errors(&ps))
		return (write(1, "Error\n", 6));
	init_stacks(&ps);
	build_pile(&ps);
	check(&ps);
	if (is_sorted(ps.a) && ps.b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(ps.a.array);
	free(ps.b.array);
	return (0);
}
