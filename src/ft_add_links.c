/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:08:12 by student           #+#    #+#             */
/*   Updated: 2020/10/07 19:49:24 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		write_link(t_lemin *lemin)
{
	t_link	*new_link;

	lemin->flag_err = 0;
	new_link = ft_create_link(NULL, NULL);
	if (!lemin->top_links)
		lemin->top_links = new_link;
	else
		add_list_links(&lemin->top_links, new_link);
	create_link(lemin);
	if (lemin->flag_err == 0)
		ft_error("ERROR\n");
	if (new_link->next != NULL)
		check_links_dup(lemin->top_links, new_link);
	if (lemin->visual == 1)
		ft_printf("%s %s\n", new_link->begin->name, new_link->end->name);
}

void		add_list_links(t_link **top_links, t_link *link)
{
	link->next = *top_links;
	(*top_links)->prev = link;
	*top_links = link;
}

void		create_link(t_lemin *lemin)
{
	char	*dash;
	char	*start_name;
	char	*end_name;
	t_room	*start_room;
	t_room	*end_room;

	dash = lemin->line;
	while ((dash = ft_strchr(dash + 1, '-')))
	{
		if (!(start_name = ft_strsub(lemin->line, 0, dash - lemin->line)))
			ft_error("ERROR\n");
		if (!(end_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
			ft_error("ERROR\n");
		start_room = find_room(lemin, start_name);
		end_room = find_room(lemin, end_name);
		ft_free(start_name, end_name);
		if (start_room && end_room)
		{
			if (start_room->name == end_room->name)
				ft_error("ERROR\n");
			lemin->top_links->begin = start_room;
			lemin->top_links->end = end_room;
			lemin->flag_err = 1;
		}
	}
}

t_room		*find_room(t_lemin *lemin, char *name)
{
	t_room	*current;

	current = lemin->top_rooms;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
			return (current);
		current = current->next_in_list;
	}
	return (NULL);
}
