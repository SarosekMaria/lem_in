/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assasin <assasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 21:40:06 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/26 16:37:23 by assasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

//file for printing rooms and links

void	ft_print_input(t_lemin *lemin)
{
	while(lemin->Output->prev)
		lemin->Output = lemin->Output->prev;
	while(lemin->Output->next)
	{
		ft_printf("%s\n", lemin->Output->content);
		lemin->Output = lemin->Output->next;
	}
	ft_printf("%s\n\n", lemin->Output->content);
}

void	ft_print_fpath(t_fpath **top_fpath)
{
	t_fpath	*tmp;

	if (top_fpath && *top_fpath)
	{
		tmp = *top_fpath;
		ft_printf("Fpath:");
		while (tmp)
		{
			ft_printf("%s ", tmp->room->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

void	ft_print_path(t_path *path)
{
	ft_printf("len: %u\n", path->len);
	ft_print_fpath(&path->top_fpath);
}

void	ft_print_group(t_group *group)
{
	size_t	i;

	ft_printf("*************GROUP**********\n");
	ft_printf("Num_of_paths = %u\tNum_of_turns = %u\n", group->num_of_paths,
														group->num_of_turns);
	i = 0;
	while (i < group->num_of_paths)
	{
		ft_printf("Path #%u\n", i);
		ft_print_path(group->paths[i]);
		ft_printf("num_of_ants: %u\n", group->ants[i]);
		i++;
		ft_printf("\n");
	}
	ft_printf("*************GROUP**********\n");
}

void	ft_print_room_links(t_list **links)
{
	t_list	*room_link;

	room_link = *links;
	ft_printf("Links: ");
	while (room_link)
	{
		ft_printf("%s ", ((t_room *)(room_link->content))->name);
		room_link = room_link->next;
	}
	ft_printf("\n");
}

void	ft_print_rooms(t_room **head)
{
	t_room	*tmp;
//	t_list	*room_link;

	tmp = *head;
	while (tmp)
	{
		ft_printf("Room %s\n", tmp->name);
		ft_printf("status:%d\nlinks_count:%u\n", tmp->status, tmp->links_count);
		ft_print_room_links(&tmp->neighbours);
/*		while (room_link)
		{
			ft_printf("%s ", ((t_room *)(room_link->content))->name);
			room_link = room_link->next;
		}*/
		tmp = tmp->next_in_list;
		ft_printf("\n\n");
	}
	ft_printf("\n");
}

void	ft_print_links(t_link **head)
{
	t_link	*tmp;

	tmp = *head;
	ft_printf("*********LINKS***********\n");
	while (tmp)
	{
		ft_printf("%s-%s\n", tmp->begin->name, tmp->end->name);
		tmp = tmp->next;
	}
	ft_printf("**************************\n");
}
