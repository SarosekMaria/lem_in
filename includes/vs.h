/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:14:14 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 20:17:59 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_H

# define VS_H

# include "ft_lemin.h"
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL2_gfxPrimitives.h>

typedef struct		s_vs
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_vs;

typedef struct		s_roomv
{
	char			*name;
	int				x;
	int				y;
	struct s_roomv	*next;
}					t_roomv;

typedef struct		s_linkv
{
	t_roomv			*begin;
	t_roomv			*end;
	struct s_linkv	*next;
	struct s_linkv	*prev;
}					t_linkv;

typedef struct		s_antv
{
	char			*content;
	struct s_antv	*next;
	struct s_antv	*prev;
}					t_antv;

typedef struct		s_leminv
{
	int				ant;
	int				flag;
	t_roomv			*startroom;
	t_roomv			*room;
	t_linkv			*links;
	t_antv			*ants;
	char			*line;
}					t_leminv;

t_vs				*create_vs(void);
SDL_Window			*create_window(t_vs *vs);
SDL_Renderer		*create_renderer(t_vs *vs);
void				init_vs(t_vs *vs);
void				free_strv(char **str);
t_linkv				*ft_create_linkv(t_roomv *begin, t_roomv *end);
void				ft_del_linkv(t_linkv **link);
void				ft_del_linksv(t_linkv **head);
void				add_list_linksv(t_linkv **top_links, t_linkv *link);
t_roomv				*find_roomsv(t_leminv *lemin, char *name);
void				create_linkv(t_leminv *lemin);
void				write_linkv(t_leminv *lemin);
t_roomv				*ft_create_roomv(char *name, int x, int y);
void				ft_del_roomv(t_roomv **room);
void				ft_del_roomsv(t_roomv **head);
void				ft_del_antsv(t_antv **ant);
void				ft_del_antv(t_antv **ant);
t_leminv			*ft_init_leminv(void);
void				ft_del_leminv(t_leminv **lemin);
t_antv				*ft_add_antv(t_antv *ant, char *str);
t_antv				*ft_create_antv(char *cont);
void				draw_links(t_leminv *lemin, t_vs *vs);
void				draw_rectant(int x, int y, t_vs *vs);
void				draw_ant(t_leminv *lemin, t_antv *link, t_vs *vs,
							char *str_ant);
void				draw_rooms(t_leminv *lemin, t_vs *vs);
void				while_strv(t_leminv *lemin, char **str, int i);
void				while_str2(t_leminv *lemin, char **str, int i);
void				add_list_roomv(t_roomv **top_rooms, t_roomv *room);
void				write_roomv(t_leminv *lemin, int space);
void				checkstr(char **str);
int					check_room_or_linkv(t_leminv *lemin);
void				ft_add_datav(t_leminv *lemin);
void				ft_freev(t_leminv *lemin, t_vs *vs);
void				utils(char *str, char *str_ant, t_leminv *lemin);

#endif
