/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/30 22:08:36 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void			ft_del_roomv(t_roomv **room)
{
	if (room != NULL && *room)
	{
		ft_strdel(&((*room)->name));
		free(*room);
		*room = NULL;
	}
}

void			ft_del_roomsv(t_roomv **head)
{
	t_roomv		*tmp;

	if (head != NULL && *head)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_roomv(head);
			*head = tmp;
		}
		ft_del_roomv(head);
		*head = NULL;
	}
}

void			ft_del_antsv(t_antv **ant)
{
	if (ant != NULL && *ant)
	{
		ft_strdel(&((*ant)->content));
		(*ant)->next = NULL;
		(*ant)->prev = NULL;
		free(*ant);
		(*ant) = NULL;
	}
}

void			ft_del_antv(t_antv **ant)
{
	t_antv		*tmp;

	if (ant != NULL && *ant)
	{
		while ((*ant)->prev)
		{
			tmp = (*ant)->prev;
			ft_del_antsv(ant);
			*ant = tmp;
		}
		ft_del_antsv(ant);
		*ant = NULL;
	}
}

t_leminv		*ft_init_leminv(void)
{
	t_leminv	*lemin;

	lemin = (t_leminv*)malloc(sizeof(t_leminv) * 1);
	if (lemin)
	{
		lemin->ant = 0;
		lemin->flag = 1;
		lemin->room = NULL;
		lemin->links = NULL;
		lemin->ants = NULL;
		lemin->line = NULL;
	}
	return (lemin);
}
