/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_dead_ends.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assasin <assasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 20:49:24 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/26 15:01:21 by assasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void    ft_delonelst(t_list **top, t_list *tmp)
{
    t_list  *tmp_prev;

    if (top && *top && tmp)
    {
        if (*top == tmp)
        {
      //      ft_printf("elem is first\n");
            *top = (*top)->next;
        }
        else if (tmp->next != NULL)
        {
     //       ft_printf("elem is middle\n");
            tmp_prev = *top;
            while (tmp_prev->next != tmp)
                tmp_prev = tmp_prev->next;
            tmp_prev->next = tmp->next;
        }
        else
        {
    //        ft_printf("elem is last\n");
            tmp_prev = *top;
            while (tmp_prev->next->next)
                tmp_prev = tmp_prev->next;
            tmp_prev->next = NULL;
        }
        ft_lstdelone(&tmp, NULL);
    }
}

static void    ft_del_dead_link(t_room *src_room, t_room *del_room)
{
    t_list  *tmp;

    tmp = src_room->neighbours;
	src_room->links_count--;
//	ft_printf("Ft_del_dead_link links:\n");
//	ft_print_room_links(&src_room->neighbours);
//	ft_printf("\n");
    while (((t_room *)(tmp->content)) != del_room)
        tmp = tmp->next;
//    ft_printf("Del from links list of room %s room %s\n", src_room->name,((t_room *)(tmp->content))->name);
    ft_delonelst(&src_room->neighbours, tmp);
}

void	ft_del_dead_ends(t_room **top_rooms)
{
    t_room  *tmp;

    tmp = *top_rooms;
    while (tmp)
    {
        if (tmp->links_count <= 1)
        {
//          ft_printf("deleting dead end: %s(links->count = %d)\n", tmp->name, tmp->links_count);
		  	if (tmp->links_count == 1)
                ft_del_dead_link((t_room *)((tmp->neighbours->content)), tmp);
            ft_delone_room(top_rooms, tmp);
            tmp = *top_rooms;
        }
        else
            tmp = tmp->next_in_list;
    }
}
