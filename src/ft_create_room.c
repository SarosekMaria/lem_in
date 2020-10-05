/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:43 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 20:20:04 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_room		*ft_create_room(char *name, int x, int y)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room) * 1);
	if (!new)
		return (NULL);
	new->name = name;
	new->status = 1;
	new->x = x;
	new->y = y;
	new->visited = 0;
	new->flag_v = 0;
	new->links_count = 0;
	new->neighbours = NULL;
	new->next_room = NULL;
	new->prev_room = NULL;
	new->next_in_list = NULL;
	return (new);
}

void		ft_delone_room(t_room **top_rooms, t_room *room)
{
	t_room	*tmp_prev;

	if (top_rooms && *top_rooms && room)
	{
		ft_lstdel(&room->neighbours, NULL);
		if (*top_rooms == room)
			*top_rooms = (*top_rooms)->next_in_list;
		else if (room->next_in_list != NULL)
		{
			tmp_prev = *top_rooms;
			while (tmp_prev->next_in_list != room)
				tmp_prev = tmp_prev->next_in_list;
			tmp_prev->next_in_list = room->next_in_list;
		}
		else
		{
			tmp_prev = *top_rooms;
			while (tmp_prev->next_in_list->next_in_list)
				tmp_prev = tmp_prev->next_in_list;
			tmp_prev->next_in_list = NULL;
		}
		ft_del_room(&room);
	}
}

void		ft_del_room(t_room **room)
{
	if (room != NULL && *room)
	{
		ft_strdel(&((*room)->name));
		(*room)->status = 0;
		(*room)->x = 0;
		(*room)->y = 0;
		(*room)->visited = 0;
		(*room)->flag_v = 0;
		(*room)->links_count = 0;
		if ((*room)->neighbours != NULL)
			ft_lstdel(&((*room)->neighbours), NULL);
		(*room)->next_room = NULL;
		(*room)->prev_room = NULL;
		(*room)->next_in_list = NULL;
		free(*room);
		*room = NULL;
	}
}

void		ft_del_rooms(t_room **head)
{
	t_room	*tmp;

	if (head != NULL && *head)
	{
		tmp = *head;
		while (tmp)
		{
			ft_lstdel(&(tmp->neighbours), NULL);
			tmp = tmp->next_in_list;
		}
		while ((*head)->next_in_list)
		{
			tmp = (*head)->next_in_list;
			ft_del_room(head);
			*head = tmp;
		}
		ft_del_room(head);
		*head = NULL;
	}
}
