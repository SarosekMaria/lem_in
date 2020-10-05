
#ifndef VS_H

# define VS_H

# include "ft_lemin.h"
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL2_gfxPrimitives.h>

# define WIDTH				1920
# define HEIGHT				1080
# define ROOM_WIDTH			100
# define ROOM_HEIGHT		100

# define DESTROY_TEXTURE(X)	if (X) SDL_DestroyTexture(X);

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
	int				minX;
	int				minY;
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



#endif
