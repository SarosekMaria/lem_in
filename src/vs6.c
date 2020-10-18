/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 20:31:03 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

t_vs			*create_vs(void)
{
	t_vs		*vs;

	vs = (t_vs *)ft_memalloc(sizeof(t_vs));
	vs->window = NULL;
	vs->renderer = NULL;
	return (vs);
}

int				check_room_or_linkv(t_leminv *lemin)
{
	int			i;
	int			space;
	char		**str;

	i = 0;
	space = 0;
	str = ft_strsplit(lemin->line, ' ');
	while (lemin->line[i] != '\0')
	{
		if (lemin->line[i] == ' ')
			space++;
		i++;
	}
	checkstr(str);
	if (space > 1)
		write_roomv(lemin, space);
	if (space == 1)
		write_linkv(lemin);
	if (space == 0)
		lemin->ant = ft_atoi(lemin->line);
	return (0);
}

void			ft_add_datav(t_leminv *lemin)
{
	int			i;

	i = 0;
	while (get_next_line(0, &lemin->line) > 0)
	{
		if (lemin->line[0] == 'L')
		{
			if (!lemin->ants)
				lemin->ants = ft_create_antv(lemin->line);
			else
				lemin->ants = ft_add_antv(lemin->ants, lemin->line);
		}
		else
			check_room_or_linkv(lemin);
		free(lemin->line);
	}
}

void			draw_links(t_leminv *lemin, t_vs *vs)
{
	t_linkv		*current;

	current = lemin->links;
	SDL_SetRenderDrawColor(vs->renderer, 0x00, 0x00, 0x00, 0x00);
	while (current)
	{
		SDL_RenderDrawLine(vs->renderer,
		current->begin->x + 50,
		current->begin->y + 50,
		current->end->x + 50,
		current->end->y + 50);
		current = current->next;
	}
}

void			utils(char *str, char *str_ant, t_leminv *lemin)
{
	size_t		len;
	char		*str_new;

	len = 0;
	len = ft_strlen(str);
	str_new = ft_strsub(str, 1, len - 1);
	if (!ft_strcmp(str_ant, str_new))
		lemin->flag = 0;
	free(str_new);
}
