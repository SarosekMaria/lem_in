#include "ft_lemin.h"

void	ft_select_best_outlink(t_lemin *lemin)
{
	t_path	*tmp_path;
	t_path	*surviving_path;

	tmp_path = lemin->top_paths->next;
	surviving_path = lemin->top_paths;
	while (tmp_path)
	{
		if (tmp_path->length < surviving_path->length)
			surviving_path = tmp_path;
		tmp_path = tmp_path->next;
	}
	ft_del_other_links(lemin, surviving_path);
}

void		ft_create_se_path(t_link *head_link, t_lemin *lemin)
{
	t_path	*new_path;
	t_room	*begin;
	t_room	*end;
	t_link	*tmp;

	new_path = ft_create_path(head_link, 1);
	begin = head_link->begin;
	end = head_link->end;
	while (end != lemin->end)
	{
ft_printf("lemin->end = %s, begin = %s, end = %s\n", lemin->end->name, begin->name, end->name);
//getchar();
		tmp = lemin->top_links;
		while (tmp->begin != end)
			tmp = tmp->next;
		new_path->length++;
		end = tmp->end;
		begin = tmp->begin;
ft_printf("lemin->end = %s, begin = %s, end = %s\n", lemin->end->name, begin->name, end->name);
//getchar();
	}
	ft_add_path(&lemin->top_paths, new_path);
ft_printf("new_path->length = %d\n", new_path->length);
}

void		ft_del_outforks(t_lemin *lemin)
{
	t_room	*tmp_room;
	t_link	*tmp_link;

	while (lemin->max_bfs > 0)
	{
		tmp_room = lemin->top_rooms;
		while (tmp_room)
		{
			if (tmp_room->outputs > 1 && tmp_room->bfslvl == lemin->max_bfs)
			{
				tmp_link = lemin->top_links;
				while (tmp_link)
				{
					if (tmp_link->begin == tmp_room)
						ft_create_se_path(tmp_link, lemin);
					tmp_link = tmp_link->next;
				}
				ft_select_best_outlink(lemin);
			}
			tmp_room = tmp_room->next;
		}
		lemin->max_bfs--;
	}
}
