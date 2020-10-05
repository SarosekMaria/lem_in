/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_gpaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:16 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 18:43:04 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_path		*ft_assemble_path(t_room *src, t_room *dst)
{
	t_path	*path;
	t_room	*tmp;
	t_fpath	*last;
	t_fpath	*new_fpath;

	path = ft_create_path();
	path->top_fpath = ft_create_fpath(src);
	tmp = dst;
	last = path->top_fpath;
	path->len++;
	while (tmp)
	{
		new_fpath = ft_create_fpath(tmp);
		last->next = new_fpath;
		last = new_fpath;
		path->len++;
		tmp = tmp->next_room;
	}
	return (path);
}

void		ft_create_gpaths(t_room *start, t_group *group)
{
	t_list	*tmp;
	t_path	*path;
	t_room	*room;
	size_t	i;

	i = 0;
	tmp = start->neighbours;
	while (tmp)
	{
		room = ((t_room *)(tmp->content));
		if (room->next_room || room->status == 2)
		{
			path = ft_assemble_path(start, room);
			group->paths[i] = path;
			i++;
		}
		tmp = tmp->next;
	}
}

size_t		ft_count_gpaths(t_room *start)
{
	size_t	count;
	t_list	*tmp;

	tmp = start->neighbours;
	count = 0;
	while (tmp)
	{
		if (((t_room *)(tmp->content))->next_room ||
			((t_room *)(tmp->content))->status == 2)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
