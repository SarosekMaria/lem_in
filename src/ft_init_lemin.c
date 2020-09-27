#include "ft_lemin.h"

void	ft_exit(t_lemin *lemin, int flag)
{
	if (flag == 0)
		ft_printf("ERROR: there are no one valid path\n");
	else
		ft_printf("UNKNOWN ERROR!\n");
	ft_del_lemin(&lemin);
	exit(0);
}

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
		lemin->best_group = NULL;
		lemin->head_ants = NULL;
		lemin->tail_ants = NULL;
		lemin->num_of_ants = 0;
		lemin->ants_at_the_end = 0;
		lemin->line = NULL;
		lemin->Output = NULL;
		lemin->flag_end_begin = 0;
		lemin->fd = 0;
	}
	return (lemin);
}

void	ft_del_lemin(t_lemin **lemin)
{
	if (lemin && *lemin)
	{
		ft_del_rooms(&((*lemin)->top_rooms));
		ft_del_links(&((*lemin)->top_links));
		ft_del_group((*lemin)->best_group);
//		ft_strdel(&((*lemin)->line));
		ft_del_Output(&(*lemin)->Output);
		(*lemin)->start = NULL;
		(*lemin)->end = NULL;
		(*lemin)->head_ants = NULL;
		(*lemin)->tail_ants = NULL;
		(*lemin)->num_of_ants = 0;
		(*lemin)->ants_at_the_end = 0;
		free(*lemin);
		*lemin = NULL;
	}
}
