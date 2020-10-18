/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:25:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 20:36:42 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_check_neighbour(t_room *room, t_link *link)
{
	if (link->begin == room)
	{
		room->links_count++;
		ft_lstadd(&room->neighbours,
				ft_lstnew(link->end, sizeof(t_room *)));
	}
	else if (link->end == room)
	{
		room->links_count++;
		ft_lstadd(&room->neighbours,
				ft_lstnew(link->begin, sizeof(t_room *)));
	}
}

void		ft_adjacency_matrix(t_room **top_rooms, t_link **top_links)
{
	t_room	*room;
	t_link	*link;

	if (top_rooms && *top_rooms && top_links && *top_links)
	{
		room = *top_rooms;
		while (room)
		{
			link = *top_links;
			while (link)
			{
				ft_check_neighbour(room, link);
				link = link->next;
			}
			room = room->next_in_list;
		}
	}
}

void		add_list_room(t_room **top_rooms, t_room *room)
{
	room->next_in_list = *top_rooms;
	*top_rooms = room;
}

void		ft_free(char *start_name, char *end_name)
{
	free(start_name);
	free(end_name);
}

int			main(int argc, char **argv)
{
	t_lemin	*lemin;

	lemin = ft_init_lemin();
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "-v"))
			lemin->visual = 1;
	}
	check_input(lemin);
	if (lemin)
	{
		ft_adjacency_matrix(&lemin->top_rooms, &lemin->top_links);
		ft_del_dead_ends(&lemin->top_rooms, lemin);
		if (ft_solution(lemin) == -1)
			ft_exit(lemin, 0);
		if (lemin->visual == 0)
			ft_print_input(lemin);
		ft_manipulate_ant(lemin, lemin->best_group);
		ft_del_lemin(&lemin);
	}
	return (0);
}
