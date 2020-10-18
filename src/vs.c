/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 21:58:47 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void				do_draw(t_leminv *lemin, t_vs *vs, char *str)
{
	ft_printf("%s\n", lemin->ants->content);
	draw_rooms(lemin, vs);
	draw_links(lemin, vs);
	draw_ant(lemin, lemin->ants, vs, str);
	SDL_RenderPresent(vs->renderer);
	SDL_Delay(1000);
	SDL_DestroyRenderer(vs->renderer);
	vs->renderer = SDL_CreateRenderer(vs->window, -1, SDL_WINDOW_SHOWN);
}

int					main(void)
{
	t_leminv		*lemin;
	t_vs			*vs;
	SDL_Event		event;
	char			*str;

	vs = create_vs();
	init_vs(vs);
	SDL_SetRenderDrawColor(vs->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(vs->renderer);
	SDL_RenderPresent(vs->renderer);
	lemin = ft_init_leminv();
	ft_add_datav(lemin);
	while (lemin->ants->prev)
		lemin->ants = lemin->ants->prev;
	str = ft_itoa(lemin->ant);
	while (lemin->ants)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break ;
		do_draw(lemin, vs, str);
		lemin->ants = lemin->ants->next;
	}
	ft_freev(lemin, vs);
	return (1);
}

void				draw_rooms(t_leminv *lemin, t_vs *vs)
{
	t_roomv			*current;
	SDL_Rect		dims;

	current = lemin->room;
	dims.w = 100;
	dims.h = 100;
	while (current)
	{
		if (!ft_strcmp(current->name, lemin->startroom->name))
			SDL_SetRenderDrawColor(vs->renderer, 0x50, 0x16, 0x00, 0x25);
		else
			SDL_SetRenderDrawColor(vs->renderer, 0x00, 0x00, 0x00, 0x00);
		dims.x = current->x;
		dims.y = current->y;
		SDL_RenderFillRect(vs->renderer, &dims);
		current = current->next;
	}
}

SDL_Renderer		*create_renderer(t_vs *vs)
{
	SDL_Renderer	*renderer;

	renderer = SDL_CreateRenderer(vs->window, -1, SDL_WINDOW_SHOWN);
	return (renderer);
}

void				init_vs(t_vs *vs)
{
	vs->window = SDL_CreateWindow("Lem-in",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	1920, 1080, 0);
	vs->renderer = create_renderer(vs);
}
