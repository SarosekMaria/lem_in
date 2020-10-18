/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 20:32:28 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void			ft_del_leminv(t_leminv **lemin)
{
	if (lemin && *lemin)
	{
		(*lemin)->flag = 0;
		(*lemin)->ant = 0;
		(*lemin)->line = NULL;
		ft_del_roomsv(&((*lemin)->room));
		ft_del_linksv(&((*lemin)->links));
		ft_del_antv(&(*lemin)->ants);
		free(*lemin);
		*lemin = NULL;
	}
}

t_antv			*ft_add_antv(t_antv *ant, char *str)
{
	t_antv		*curr;

	curr = (t_antv*)malloc(sizeof(t_antv) * 1);
	if (!curr)
		return (NULL);
	ant->next = curr;
	curr->content = ft_strdup(str);
	curr->prev = ant;
	curr->next = NULL;
	return (curr);
}

t_antv			*ft_create_antv(char *cont)
{
	t_antv		*new;

	new = (t_antv*)malloc(sizeof(t_antv) * 1);
	if (!new)
		return (NULL);
	new->content = ft_strdup(cont);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			draw_rectant(int x, int y, t_vs *vs)
{
	SDL_Rect	dims;

	SDL_SetRenderDrawColor(vs->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	dims.w = 60;
	dims.h = 60;
	dims.x = x + 20;
	dims.y = y + 20;
	SDL_RenderFillRect(vs->renderer, &dims);
}

void			draw_ant(t_leminv *lemin, t_antv *link, t_vs *vs, char *str_ant)
{
	char		**str;
	char		**str_r;
	t_roomv		*room;
	int			i;

	str = ft_strsplit(link->content, ' ');
	i = 0;
	while (str[i])
	{
		str_r = ft_strsplit(str[i], '-');
		room = lemin->room;
		while (room)
		{
			if (!ft_strcmp(room->name, str_r[1]))
				draw_rectant(room->x, room->y, vs);
			room = room->next;
		}
		utils(str_r[0], str_ant, lemin);
		i++;
		free_strv(str_r);
	}
	if (lemin->flag != 0)
		draw_rectant(lemin->startroom->x, lemin->startroom->y, vs);
	free_strv(str);
}
