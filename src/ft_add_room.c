/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:19:23 by student           #+#    #+#             */
/*   Updated: 2020/10/06 16:19:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		check_room_dup(t_room *lst, t_room *new_r)
{
	new_r = new_r->next_in_list;
	while (new_r->next_in_list)
	{
		if (!ft_strcmp(new_r->name, lst->name))
			ft_error("ERROR: duplicate room\n");
		else if (new_r->x == lst->x && lst->y == new_r->y)
			ft_error("ERROR: duplicate room coordinates\n");
		else
			new_r = new_r->next_in_list;
	}
}

void		parse_room(t_lemin *lemin)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (lemin->line[i] != '\0')
	{
		if (lemin->line[i] == ' ')
			space++;
		i++;
	}
	if (space == 2)
		write_room(lemin);
	else
		ft_error("ERROR: incorrect input data\n");
}

void		print_vis(t_lemin *lemin)
{
	if (lemin->top_rooms->status == 0)
		ft_printf("%s %d %d start\n", lemin->top_rooms->name,
		lemin->top_rooms->x, lemin->top_rooms->y);
	else
		ft_printf("%s %d %d\n", lemin->top_rooms->name,
		lemin->top_rooms->x, lemin->top_rooms->y);
}

void		write_room(t_lemin *lemin)
{
	int		i;
	char	**str;
	t_room	*new_room;

	i = 0;
	str = ft_strsplit(lemin->line, ' ');
	if (str[0][0] == 'L' || str[0][0] == '#')
		ft_error("ERROR: incorrect input data\n");
	new_room = ft_create_room(NULL, 0, 0);
	if (!lemin->top_rooms)
		lemin->top_rooms = new_room;
	else
		add_list_room(&lemin->top_rooms, new_room);
	while (str[i])
	{
		while_str(lemin, str, i);
		i++;
	}
	if (new_room->next_in_list != NULL)
		check_room_dup(lemin->top_rooms, new_room);
	free_str(str);
	if (lemin->visual == 1)
		print_vis(lemin);
}

void		while_str(t_lemin *lemin, char **str, int i)
{
	if (i == 0)
	{
		lemin->top_rooms->name = ft_strdup(str[0]);
	}
	if (i > 0 && !isdigit_my(str, i))
		ft_error("ERROR: incorrect input data\n");
	if (i > 0 && !ft_val_overflow(str[i]))
		ft_error("ERROR: incorrect input data\n");
	if (i == 1)
		lemin->top_rooms->x = ft_atoi(str[i]);
	if (i == 2)
		lemin->top_rooms->y = ft_atoi(str[i]);
	if (lemin->flag_end_begin == 1)
	{
		lemin->top_rooms->status = 0;
		lemin->start = lemin->top_rooms;
	}
	if (lemin->flag_end_begin == 2)
	{
		lemin->top_rooms->status = 2;
		lemin->end = lemin->top_rooms;
	}
	lemin->flag_end_begin = 0;
}
