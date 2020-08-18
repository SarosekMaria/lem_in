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
		lemin->max_bfs = 0;
	}
	return (lemin);
}

void	ft_del_lemin(t_lemin **lemin)
{
	if (lemin)
	{
		ft_del_rooms(&((*lemin)->top_rooms));
		ft_del_links(&((*lemin)->top_links));
		(*lemin)->start = NULL;
		(*lemin)->end = NULL;
		(*lemin)->max_bfs = 0;
		free(*lemin);
		*lemin = NULL;
	}
}
