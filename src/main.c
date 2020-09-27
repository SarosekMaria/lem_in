/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assasin <assasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:25:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/27 17:34:59 by assasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_check_neighbour(t_room *room, t_link *link)
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

void	ft_adjacency_matrix(t_room **top_rooms, t_link **top_links)
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
//			ft_printf("Links of room %s: ", room->name);
//			ft_print_room_links(&room->neighbours);
//			ft_printf("\n");
			room = room->next_in_list;
		}
	}
}

int main()
{
	t_lemin	*lemin;

	lemin = ft_init_lemin();
	check_input(lemin);

/*	t_room *c_r = lemin->top_rooms;
	while (c_r)
	{
		if(c_r->status == 0)
			lemin->start = c_r;
		if(c_r->status == 2)
			lemin->end = c_r;
		c_r=c_r->next_in_list;
	}*/	

	if (lemin)
	{
//		ft_print_rooms(&lemin->top_rooms);
		ft_adjacency_matrix(&lemin->top_rooms, &lemin->top_links);
		ft_del_dead_ends(&lemin->top_rooms);
//		ft_printf("Rooms after deleting dead ends\n");
//		ft_print_rooms(&lemin->top_rooms);
		if (ft_solution(lemin) == -1)
			ft_exit(lemin, 0);
		ft_print_input(lemin);
//		ft_print_group(lemin->best_group);
		ft_manipulate_ant(lemin, lemin->best_group);
		ft_printf("total rounds = %u\n", lemin->best_group->num_of_turns);
		ft_del_lemin(&lemin);
	}
	return (0);
}
