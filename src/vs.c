/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:38:30 by vbrazhni          #+#    #+#             */
/*   Updated: 2020/09/30 22:08:36 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
//#include "get_next_line.h"
//#include <stdio.h>

void        free_strv(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_linkv	*ft_create_linkv(t_roomv *begin, t_roomv *end)
{
	t_linkv	*new;

	new = (t_linkv*)malloc(sizeof(t_linkv) * 1);
	if (!new)
		return (NULL);
	new->begin = begin;
	new->end = end;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_del_linkv(t_linkv **link)
{
	if (link != NULL && *link)
	{
		(*link)->begin = NULL;
		(*link)->end = NULL;
		(*link)->next = NULL;
		(*link)->prev = NULL;
		free(*link);
		(*link) = NULL;
	}
}

void	ft_del_linksv(t_linkv **head)
{
	t_linkv	*tmp;

	if (head != NULL && *head)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_linkv(head);
			*head = tmp;
		}
		ft_del_linkv(head);
		*head = NULL;
	}
}


void        add_list_linksv(t_linkv **top_links, t_linkv *link)
{
    link->next = *top_links;
	(*top_links)->prev = link;
	*top_links = link;
}

t_roomv      *find_roomsv(t_leminv *lemin, char *name)
{
	t_roomv	*current;

	current = lemin->room;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

void        create_linkv(t_leminv *lemin)
{
	char	**dash;
	char	*start_name;
	char	*end_name;
	t_roomv	*start_room;
	t_roomv	*end_room;

	dash = ft_strsplit(lemin->line, ' ');
	start_name = ft_strdup(dash[0]);
	end_name =ft_strdup(dash[1]);
		start_room = find_roomsv(lemin, start_name);
		end_room = find_roomsv(lemin, end_name);
		free(start_name);
		free(end_name);
        lemin->links->begin = start_room;
        lemin->links->end = end_room;			
}


void        write_linkv(t_leminv *lemin)
{
	t_linkv	*new_link;

	new_link = ft_create_linkv(NULL, NULL);
	if (!lemin->links)
		lemin->links = new_link;	
	else
		add_list_linksv(&lemin->links, new_link);
	create_linkv(lemin);
}


t_roomv	*ft_create_roomv(char *name, int x, int y)
{
	t_roomv	*new;

	new = (t_roomv*)malloc(sizeof(t_roomv) * 1);
	if (!new)
		return (NULL);
	new->name = name;//под каждый name будет выделяться память
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void	ft_del_roomv(t_roomv **room)
{
	if (room != NULL && *room)
	{
		ft_strdel(&((*room)->name));
		free(*room);
		*room = NULL;
	}
}

void	ft_del_roomsv(t_roomv **head)
{
	t_roomv	*tmp;

	if (head != NULL && *head)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_roomv(head);
			*head = tmp;
		}
		ft_del_roomv(head);
		*head = NULL;
	}
}



void		ft_del_antsv(t_antv **ant)
{
	if (ant != NULL && *ant)
	{
		ft_strdel(&((*ant)->content));
		(*ant)->next = NULL;
		(*ant)->prev = NULL;
		free(*ant);
		(*ant) = NULL;
	}
}

void		ft_del_antv(t_antv **ant)
{
	t_antv	*tmp;

	if (ant != NULL && *ant)
	{
		while ((*ant)->prev)
		{
			tmp = (*ant)->prev;
			ft_del_antsv(ant);
			*ant= tmp;
		}
		ft_del_antsv(ant);
		*ant = NULL;
	}
}

t_leminv	*ft_init_leminv(void)
{
	t_leminv *lemin;

	lemin = (t_leminv*)malloc(sizeof(t_leminv) * 1);
	if (lemin)
	{
		lemin->ant = 0;
		lemin->flag = 1;
		lemin->minX = 0;
		lemin->minY = 0;
		lemin->room = NULL;
		lemin->links = NULL;
		lemin->ants = NULL;
		lemin->line = NULL;	
	}
	return (lemin);
}

void	ft_del_leminv(t_leminv **lemin)
{
	if (lemin && *lemin)
	{
		ft_del_roomsv(&((*lemin)->room));
		ft_del_linksv(&((*lemin)->links));
		ft_del_antv(&(*lemin)->ants);
		free(*lemin);
		*lemin = NULL;
	}
}
t_antv		*ft_add_antv(t_antv *ant, char *str)
{
	t_antv	*curr;

	curr = (t_antv*)malloc(sizeof(t_antv) * 1);
	if (!curr)
		return (NULL);
	ant->next = curr;
	curr->content = ft_strdup(str);
	curr->prev = ant;
	curr->next = NULL;
	return (curr);
}

t_antv		*ft_create_antv(char *cont)
{
	t_antv	*new;

	new = (t_antv*)malloc(sizeof(t_antv) * 1);
	if (!new)
		return (NULL);
	new->content = ft_strdup(cont);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}




void	draw_links(t_leminv *lemin, t_vs *vs)
{
	t_linkv		*current;

	current = lemin->links;
	SDL_SetRenderDrawColor(vs->renderer, 0x00, 0x00, 0x00, 0x00);
	while (current)
	{
		SDL_RenderDrawLine(vs->renderer,
			current->begin->x + 50 - lemin->minX,
			current->begin->y + 50 - lemin->minY,
			current->end->x+50 - lemin->minX,
			current->end->y+50 - lemin->minY);
		current = current->next;
	}
}

void	draw_rectAnt(int x, int y, t_vs *vs)
{
	
	SDL_Rect	dims;

SDL_SetRenderDrawColor(vs->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	dims.w = 60;
	dims.h = 60;

		dims.x = x +20;
		dims.y = y +20;
        SDL_RenderFillRect(vs->renderer, &dims);
		
}	

void	draw_ant(t_leminv *lemin, t_antv *link, t_vs *vs, char *strAnt)
{
	
	char 		**str;
	char 		**strR;
	char *strs;
	int x;
	int y;
	t_roomv		*room;
	int i;
	
	int len;
	int j;
	str = ft_strsplit(link->content, ' ');
	
	i = 0;
	x = 0;
	y=0;
	len = 0;
	j = 1;
	while (str[i])
	{
		strR = ft_strsplit(str[i], '-');
		room = lemin->room;
		while(room)
		{
			if(!ft_strcmp(room->name,strR[1]))
				{
					x=room->x;
					y=room->y;
				}
			room = room->next;		
		}
		draw_rectAnt(x,y, vs);
		len = ft_strlen(strR[0]);
		strs="";
		while(j < len)
		{
			strs= ft_strjoin(strs, strR[j]);
			j++;
		}
		if(!ft_strcmp(strAnt, strs))
			lemin->flag = 0;
		i++;
	}
//	printf("flag %d\n", lemin->flag);
	if (lemin->flag != 0)
		draw_rectAnt(lemin->startroom->x,lemin->startroom->y, vs);
	 
}

void	draw_rooms(t_leminv *lemin, t_vs *vs)
{
	t_roomv		*current;
	SDL_Rect	dims;
	 
	current = lemin->room;

	
	dims.w = 100;
	dims.h = 100;
	
	while (current)
	{
		if(!ft_strcmp(current->name, lemin->startroom->name))
	 	SDL_SetRenderDrawColor(vs->renderer, 0x50, 0x16, 0x00, 0x25);
		else
     	SDL_SetRenderDrawColor(vs->renderer, 0x00, 0x00, 0x00, 0x00);
		dims.x = current->x - lemin->minX;
		dims.y = current->y - lemin->minY;
        SDL_RenderFillRect(vs->renderer, &dims);
		current = current->next;
	}
}



SDL_Renderer	*create_renderer(t_vs *vs)
{
	SDL_Renderer	*renderer;

	renderer = SDL_CreateRenderer(vs->window, -1, SDL_WINDOW_SHOWN);
	return (renderer);
}

void	init_vs(t_vs *vs)
{
	
	vs->window = SDL_CreateWindow("Lem-in",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1920, 1080, 0);
	vs->renderer = create_renderer(vs);
}

t_vs			*create_vs(void)
{
	t_vs	*vs;

	vs = (t_vs *)ft_memalloc(sizeof(t_vs));
		
	vs->window = NULL;
	vs->renderer = NULL;
	
	return (vs);
}

void        while_strv(t_leminv *lemin, char **str, int i)
{
	if (i == 0)
	{
		lemin->room->name = ft_strdup(str[0]);
	}
	if (i == 1)
	{
		lemin->room->x = ft_atoi(str[i]);
		if(lemin->room->x < 0 &&  lemin->room->x < lemin->minX)
			lemin->minX = lemin->room->x;
	}
	if (i == 2)
	{
		lemin->room->y = ft_atoi(str[i]);
		if(lemin->room->y < 0 &&  lemin->room->y < lemin->minY)
			lemin->minY = lemin->room->y;
	}
}


void        while_str2(t_leminv *lemin, char **str, int i)
{
	if (i == 0)
	{
		lemin->startroom->name = ft_strdup(str[0]);
	}
	if (i == 1)
	{
		lemin->startroom->x = ft_atoi(str[i]);
		if(lemin->startroom->x < 0 &&  lemin->startroom->x < lemin->minX)
			lemin->minX = lemin->room->x;
	}
	if (i == 2)
	{
		lemin->startroom->y = ft_atoi(str[i]);
		if(lemin->startroom->y < 0 &&  lemin->startroom->y < lemin->minY)
			lemin->minY = lemin->startroom->y;
	}
}


void        add_list_roomv(t_roomv **top_rooms, t_roomv *room)
{
	room->next = *top_rooms;
	*top_rooms = room;
}

void        write_roomv(t_leminv *lemin, int space)
{
	int		i;
	
	char	**str;
	t_roomv	*new_room;
	t_roomv	*new_room2;

	i = 0;
	str = ft_strsplit(lemin->line, ' ');
	if(space == 3)
		{
			new_room2 = ft_create_roomv(NULL, 0, 0);
		    lemin->startroom = new_room2;
		}
	new_room = ft_create_roomv(NULL, 0, 0);
	if(!lemin->room)
		lemin->room = new_room;	
	else
		add_list_roomv(&lemin->room, new_room);
	while (str[i])
	{
		if(space == 3)
		{			
			while_str2(lemin, str, i);
		}
		while_strv(lemin, str, i);
		i++;
	}	
	free_strv(str);
}

int			check_room_or_linkv(t_leminv *lemin)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (lemin->line[i] != '\0')
	{
		if (lemin->line[i] == ' ')
			space++;
		i++;
	}
	if (space > 1)
		write_roomv(lemin, space);
	if (space == 1)
		write_linkv(lemin);
	if (space == 0)
		lemin->ant = ft_atoi(lemin->line);
	return (0);
}



void		ft_add_datav(t_leminv *lemin)
{
    int i;

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

int		main()
{
	
	t_leminv	    *lemin;
	t_vs		*vs;
	char *str;
	
		vs = create_vs();		
		init_vs(vs);
		
		

		lemin = ft_init_leminv();
		ft_add_datav(lemin);
		while(lemin->ants->prev)
			lemin->ants = lemin->ants->prev;
		
		str = ft_itoa(lemin->ant-1);
		while(lemin->ants)
		{
			
		draw_rooms(lemin, vs);
		draw_links(lemin, vs);
		draw_ant(lemin, lemin->ants, vs, str);
		SDL_RenderPresent(vs->renderer);
		SDL_Delay(5000);
		SDL_DestroyRenderer(vs->renderer);
		vs->renderer = SDL_CreateRenderer(vs->window, -1, SDL_WINDOW_SHOWN);
		lemin->ants= lemin->ants->next;
		
		}
}
