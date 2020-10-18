/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 19:36:14 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

t_roomv			*find_roomsv(t_leminv *lemin, char *name)
{
	t_roomv		*current;

	current = lemin->room;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

void			create_linkv(t_leminv *lemin)
{
	char		**dash;
	char		*start_name;
	char		*end_name;
	t_roomv		*start_room;
	t_roomv		*end_room;

	dash = ft_strsplit(lemin->line, ' ');
	start_name = ft_strdup(dash[0]);
	end_name = ft_strdup(dash[1]);
	start_room = find_roomsv(lemin, start_name);
	end_room = find_roomsv(lemin, end_name);
	free(start_name);
	free(end_name);
	lemin->links->begin = start_room;
	lemin->links->end = end_room;
}

void			write_linkv(t_leminv *lemin)
{
	t_linkv		*new_link;

	new_link = ft_create_linkv(NULL, NULL);
	if (!lemin->links)
		lemin->links = new_link;
	else
		add_list_linksv(&lemin->links, new_link);
	create_linkv(lemin);
}

t_roomv			*ft_create_roomv(char *name, int x, int y)
{
	t_roomv		*new;

	new = (t_roomv*)malloc(sizeof(t_roomv) * 1);
	if (!new)
		return (NULL);
	new->name = name;
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void			ft_freev(t_leminv *lemin, t_vs *vs)
{
	if (vs->renderer)
		SDL_DestroyRenderer(vs->renderer);
	if (vs->window)
		SDL_DestroyWindow(vs->window);
	ft_del_leminv(&lemin);
	free(vs);
}
