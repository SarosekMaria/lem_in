/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner_ant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:51:57 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:06:12 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_if_single(t_ant **tmp, t_ant **head, t_ant **tail)
{
	(*head) = NULL;
	(*tail) = NULL;
	ft_del_ant(tmp);
}

static void	ft_if_first(t_ant **tmp, t_ant **head)
{
	((*tmp)->next)->prev = NULL;
	*head = (*tmp)->next;
	ft_del_ant(tmp);
	*tmp = *head;
}

void		ft_cleaner_ant(t_ant **tmp, t_ant **head, t_ant **tail)
{
	t_ant	*tmp_next;

	if (head && tail)
	{
		if ((*tmp)->prev == NULL && (*tmp)->next != NULL)
			ft_if_first(tmp, head);
		else if ((*tmp)->prev == NULL && (*tmp)->next == NULL)
			ft_if_single(tmp, head, tail);
		else if ((*tmp)->prev != NULL && (*tmp)->next != NULL)
		{
			((*tmp)->prev)->next = (*tmp)->next;
			((*tmp)->next)->prev = (*tmp)->prev;
			tmp_next = (*tmp)->next;
			ft_del_ant(tmp);
			*tmp = tmp_next;
		}
		else if ((*tmp)->next == NULL)
		{
			*tail = (*tail)->prev;
			((*tmp)->prev)->next = NULL;
			ft_del_ant(tmp);
		}
	}
}
