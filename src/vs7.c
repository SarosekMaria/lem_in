/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/30 22:08:36 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void			while_strv(t_leminv *lemin, char **str, int i)
{
	if (i == 0)
	{
		lemin->room->name = ft_strdup(str[0]);
	}
	if (i == 1)
		lemin->room->x = ft_atoi(str[i]);
	if (i == 2)
		lemin->room->y = ft_atoi(str[i]);
}

void			while_str2(t_leminv *lemin, char **str, int i)
{
	if (i == 0)
	{
		lemin->startroom->name = ft_strdup(str[0]);
	}
	if (i == 1)
		lemin->startroom->x = ft_atoi(str[i]);
	if (i == 2)
		lemin->startroom->y = ft_atoi(str[i]);
}

void			add_list_roomv(t_roomv **top_rooms, t_roomv *room)
{
	room->next = *top_rooms;
	*top_rooms = room;
}

void			write_roomv(t_leminv *lemin, int space)
{
	int			i;
	char		**str;
	t_roomv		*new_room;
	t_roomv		*new_room2;

	i = 0;
	str = ft_strsplit(lemin->line, ' ');
	if (space == 3)
	{
		new_room2 = ft_create_roomv(NULL, 0, 0);
		lemin->startroom = new_room2;
	}
	new_room = ft_create_roomv(NULL, 0, 0);
	if (!lemin->room)
		lemin->room = new_room;
	else
		add_list_roomv(&lemin->room, new_room);
	while (str[i])
	{
		if (space == 3)
			while_str2(lemin, str, i);
		while_strv(lemin, str, i);
		i++;
	}
	free_strv(str);
}

void			checkstr(char **str)
{
	int i;

	i = 0;
	while (str[0][i] != '\0')
	{
		if (!ft_isdigit(str[0][i]))
		{
			ft_printf("error\n");
			exit(0);
		}
		i++;
	}
}
