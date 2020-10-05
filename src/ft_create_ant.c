/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:12 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 18:52:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_add_ant(t_ant **head, t_ant **tail, t_ant *ant)
{
	if (head && tail)
	{
		if (*head == NULL && *tail == NULL)
		{
			*head = ant;
			*tail = *head;
		}
		else if (*tail != NULL)
		{
			(*tail)->next = ant;
			ant->prev = *tail;
			*tail = ant;
		}
	}
}

void		ft_del_ant(t_ant **ant)
{
	if (ant && *ant)
	{
		(*ant)->cur_location = NULL;
		(*ant)->i = 0;
		(*ant)->next = NULL;
		(*ant)->prev = NULL;
		free(*ant);
		*ant = NULL;
	}
}

void		ft_del_ants(t_ant **top)
{
	t_ant	*tmp;

	if (top && *top)
	{
		while ((*top)->next)
		{
			tmp = (*top)->next;
			ft_del_ant(top);
			*top = tmp;
		}
		ft_del_ant(top);
		*top = NULL;
	}
}

t_ant		*ft_create_ant(t_fpath *cur_location, size_t i)
{
	t_ant	*new_ant;

	new_ant = (t_ant *)malloc(sizeof(t_ant) * 1);
	if (!new_ant)
		return (NULL);
	new_ant->cur_location = cur_location;
	new_ant->i = i;
	new_ant->next = NULL;
	new_ant->prev = NULL;
	return (new_ant);
}
