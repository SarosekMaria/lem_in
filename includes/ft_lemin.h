
#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# define BUFF_SIZE 1
# define MAS_SIZE 12000
# include <stdlib.h>// malloc, free, perror, exit
# include <unistd.h>// write
# include <fcntl.h>// read
# include <string.h>// strerror
# include "ft_printf.h"
# include "libft.h"

# define 	MAX_INT	2147483647

typedef struct			s_room
{
	char			*name;//названия комнат, (под каждое выделять память?)
	int			room_number;//номер комнаты - чтобы сравнивать int, а не строки в функции ft_find_local_bfs(ft_bfs.c)
	int			bfslvl;//уровень для алгоритма bfs; defualt: bfslvl == -1
	int			status;//0 - start, 1 - middle, 2 - end
	int			inputs;
	int			outputs;
	int			x;
	int			y;
	struct s_room		*next;
}						t_room;

typedef struct			s_link
{
	t_room				*begin;
	t_room				*end;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;

typedef struct			s_queue
{
	t_room			*room;//комната в очереди
	struct s_queue		*next;//указатель на следующую комнату в очереди
//предполагается добавить 2 метода: enqueue, dequeue. Также хранить head и tail.
}						t_queue;

typedef struct			s_path//путь складывается из листочков t_links
{
	t_link			*begin;//указатель на начало пути в списке t_links
	size_t			length;//длина пути
	struct s_path		*next;//вставлять пути в список по мере возрастания длины(не нужно делать массив, а затем его соритировать)
	int					output_fork;//флаг наличия output fork
}						t_path;

typedef struct			s_lemin
{
	t_room				*start;//чтобы не искать start
	t_room				*end;//чтобы не искать end
	t_room				*top_rooms;
	t_link				*top_links;
	t_path				*top_paths;
	int					number_of_ants;
	int					max_bfs;
}						t_lemin;

t_queue	*ft_new_qelem(t_room *room);
t_queue	*ft_enqueue(t_queue **tail, t_room *room, t_queue **head);
t_room	*ft_dequeue(t_queue **head, t_queue **tail);
t_link	*ft_create_link(t_room *begin, t_room *end);
t_room	*ft_create_room(char *name, int x, int y);
t_path	*ft_create_path(t_link *begin, int length);
t_lemin	*ft_init_lemin(void);
void	ft_init_room_numbers(t_room **head);
void	ft_del_room(t_room **room);
void	ft_del_rooms(t_room **head);
void	ft_del_link(t_link **link);
void	ft_del_links(t_link **head);
void	ft_del_path(t_path **path);
void	ft_del_paths(t_path **top_paths);
void	ft_del_lemin(t_lemin **lemin);
void	ft_cleaner_links(t_link **tmp, t_link **top_links);
void	ft_del_qelem(t_queue **qelem);
void	ft_print_rooms(t_room **head);
void	ft_print_room_property(t_room **top_rooms);
void	ft_print_links(t_link **head);
void	ft_print_paths(t_path **top_paths);
void	ft_bfs(t_lemin *lemin);
void	ft_del_useless_links(t_link **top_links);
void	ft_align_links(t_link **top_links);
void	ft_io_count(t_link **top_links);
void	ft_reset_io(t_link **top_links);
void	ft_del_dead_links(t_link **top_links);
void	ft_find_max_bfs(t_lemin *lemin);
void	ft_del_inforks(t_lemin *lemin);
void	ft_del_outforks(t_lemin *lemin);
void	ft_del_other_links(t_lemin *lemin, t_path *surviving_path);
void	ft_add_path(t_path **top_paths, t_path *new_path);

#endif
