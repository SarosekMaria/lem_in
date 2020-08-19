#include "ft_lemin.h"

void		ft_sort_path(t_path **top_paths, int quantity_path)
{
	t_path	*tmp;
	t_path	*new_top;
	t_path	*prev;
	int		position;

	position = 0;
	tmp = (*top_paths)->next;
	prev = *top_paths;
	new_top = (*top_paths)->next;
	while (position < quantity_path - 1 && (*top_paths)->length > tmp->length)
	{
ft_printf("position = %d\n", position);
		tmp = tmp->next;
		prev = prev->next;
		position++;
	}
	if (position <= quantity_path - 1 && position != 0)//элемент необходимо вставить в середину
	{
		prev->next = *top_paths;
		(*top_paths)->next = tmp;
		*top_paths = new_top;

	}
}

void		ft_form_path(t_lemin *lemin)
{
ft_printf("##########FT_FORM_PATH#######\n");
	t_link	*tmp;

	tmp = lemin->top_links;
//	lemin->quantity_path = 0;//по какой-то причине приходит сюда не 0, поэтому обнуляем
	ft_printf("before cycle lemin->quantity_path = %d\n", lemin->quantity_path);
	while (tmp)
	{
		if (tmp->begin == lemin->start)
		{
			ft_create_se_path(tmp, lemin);
			(lemin->quantity_path)++;
ft_printf("lemin->quantity = %d\n", lemin->quantity_path);
			ft_sort_path(&lemin->top_paths, lemin->quantity_path);
		}
		tmp = tmp->next;
	}
	ft_print_paths(&lemin->top_paths);
}

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
