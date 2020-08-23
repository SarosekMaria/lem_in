#include "ft_lemin.h"

t_lemin	*ft_init_lemin(void)
{
	t_lemin *lemin;

	lemin = (t_lemin*)malloc(sizeof(t_lemin) * 1);
	if (lemin)
	{
		lemin->start = NULL;
		lemin->end = NULL;
		lemin->top_rooms = NULL;
		lemin->top_links = NULL;
		lemin->top_paths = NULL;
		lemin->head_ants = NULL;
		lemin->tail_ants = NULL;
		lemin->max_bfs = 0;
		lemin->quantity_path = 0;
		lemin->number_of_ants = 0;
		lemin->ants_at_the_end = 0;
	}
	return (lemin);
}

void	ft_del_lemin(t_lemin **lemin)
{
	if (lemin)
	{
		ft_del_rooms(&((*lemin)->top_rooms));
		ft_del_links(&((*lemin)->top_links));
		ft_del_paths(&((*lemin)->top_paths));
		(*lemin)->start = NULL;
		(*lemin)->end = NULL;
		(*lemin)->head_ants = NULL;
		(*lemin)->tail_ants = NULL;
		(*lemin)->max_bfs = 0;
		(*lemin)->number_of_ants = 0;
		(*lemin)->ants_at_the_end = 0;
		(*lemin)->quantity_path = 0;
		free(*lemin);
		*lemin = NULL;
	}
}
