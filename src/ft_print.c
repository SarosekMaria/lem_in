/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 21:40:06 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 20:20:22 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_print_input(t_lemin *lemin)
{
	while (lemin->output->prev)
		lemin->output = lemin->output->prev;
	while (lemin->output->next)
	{
		ft_printf("%s\n", lemin->output->content);
		lemin->output = lemin->output->next;
	}
	ft_printf("%s\n\n", lemin->output->content);
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

	tmp = *head;
	while (tmp)
	{
		ft_printf("Room %s\n", tmp->name);
		ft_printf("status:%d\nlinks_count:%u\n", tmp->status, tmp->links_count);
		ft_print_room_links(&tmp->neighbours);
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
