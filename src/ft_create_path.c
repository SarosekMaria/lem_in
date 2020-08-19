#include "ft_lemin.h"
/*
void		ft_create_es_path(t_link *begin, t_lemin *lemin)//путь текущая_комната->start (движение вверх)
{
	t_link	*tmp;

	
}

void		ft_create_se_path(t_room *room, t_lemin *lemin)//путь текущая_комната->end (движение вниз)
{

}
*/

void		ft_add_path(t_path **top_paths, t_path *new_path)
{
	new_path->next = *top_paths;
	*top_paths = new_path;
}

t_path		*ft_create_path(t_link *begin, int length)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path) * 1);
	if (!new)
		return (NULL);
	new->begin = begin;
	new->length = length;
	new->output_fork = 0;
	new->next = NULL;
	return (new);
}

void		ft_del_path(t_path **path)
{
	if (path != NULL && *path)
	{
		(*path)->begin = NULL;
		(*path)->length = 0;
		free(*path);
		*path = NULL;
	}
}

void		ft_del_paths(t_path **top_paths)
{
	t_path	*tmp;

	if (top_paths != NULL && *top_paths != NULL)
	{
		while ((*top_paths)->next)
		{
			tmp = (*top_paths)->next;
			ft_del_path(top_paths);
			*top_paths = tmp;
		}
		ft_del_path(top_paths);
		*top_paths = NULL;
	}
}
