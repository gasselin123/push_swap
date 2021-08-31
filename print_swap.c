/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:10:51 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/30 11:15:08 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_inst(t_inst **inst, int n, t_push *ps)
{
	t_inst	*new;

	new = (t_inst *)malloc(sizeof(t_inst));
	if (!new)
	{
		write(1, "Linked list error\n", 18);
		ft_lstdel(&ps->inst);
		free (ps->a.array);
		free (ps->b.array);
		exit(1);
	}
	new->data = n;
	new->next = NULL;
	ft_lstaddback(inst, new);
}

t_inst	*ft_lst_last(t_inst *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstdel(t_inst **inst)
{
	t_inst	*tmp;

	while (*inst != NULL)
	{
		tmp = (*inst)->next;
		free(*inst);
		*inst = tmp;
	}
	free(*inst);
}

void	ft_lstaddback(t_inst **alst, t_inst *new)
{
	t_inst	*last;

	if (*alst)
	{
		last = ft_lst_last(*alst);
		last->next = new;
	}
	else
		*alst = new;
}
