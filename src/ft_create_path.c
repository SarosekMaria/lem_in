/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:38 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:41:27 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_nullify_path(t_room *room)
{
	t_room	*tmp;
	t_room	*next_room;

	tmp = room;
	while (tmp->prev_room && tmp->prev_room->status != 0)
		tmp = tmp->prev_room;
	while (tmp && tmp->status == 1)
	{
		next_room = tmp->next_room;
		tmp->prev_room = NULL;
		tmp->next_room = NULL;
		tmp = next_room;
	}
}

void		ft_path_modification(t_path *path)
{
	t_room	*prev_r;
	t_fpath	*tmp;

	tmp = path->top_fpath;
	while (tmp)
	{
		if (tmp->room->next_room != NULL && tmp->room->prev_room != NULL)
			ft_nullify_path(tmp->room);
		tmp = tmp->next;
	}
	tmp = path->top_fpath;
	prev_r = NULL;
	while (tmp)
	{
		if (!(prev_r != NULL && prev_r->status != 1 && tmp->room->status != 1))
		{
			if (prev_r != NULL && prev_r->status == 1)
				prev_r->next_room = tmp->room;
			if (tmp->room->status == 1)
				tmp->room->prev_room = prev_r;
		}
		prev_r = tmp->room;
		tmp = tmp->next;
	}
}

t_fpath		*ft_create_fpath(t_room *room)
{
	t_fpath	*new_fpath;

	new_fpath = (t_fpath *)malloc(sizeof(t_fpath));
	if (!new_fpath)
		return (NULL);
	new_fpath->room = room;
	new_fpath->next = NULL;
	return (new_fpath);
}

void		ft_addelem_path(t_path *path, t_room *room)
{
	t_fpath	*fpath_elem;

	if (path->top_fpath == NULL)
		path->top_fpath = ft_create_fpath(room);
	else
	{
		fpath_elem = ft_create_fpath(room);
		fpath_elem->next = path->top_fpath;
		path->top_fpath = fpath_elem;
	}
	path->len++;
}

t_path		*ft_create_path(void)
{
	t_path	*new_path;

	new_path = (t_path *)malloc(sizeof(t_path) * 1);
	if (!new_path)
		return (NULL);
	new_path->len = -1;
	new_path->top_fpath = NULL;
	return (new_path);
}
