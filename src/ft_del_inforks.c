#include "ft_lemin.h"

void		ft_create_es_path(t_link *head_link, t_lemin *lemin)
{
	t_path	*new_path;
	t_room	*begin;
	t_room	*end;
	t_link	*tmp;

	new_path = ft_create_path(head_link, 1);
	begin = head_link->begin;
	end = head_link->end;
	while (begin != lemin->start)
	{
//	ft_printf("lemin->start = %s, begin = %s, end = %s\n", lemin->start->name, begin->name, end->name);
//	getchar();
		tmp = lemin->top_links;
		while (tmp->end != begin)
			tmp = tmp->next;
		new_path->length++;
		end = tmp->end;
		begin = tmp->begin;
		if ((begin->outputs > 1 && begin != lemin->start) || end->outputs > 1)
			new_path->output_fork = 1;
//	ft_printf("lemin->start = %s, begin = %s, end = %s\n", lemin->start->name, begin->name, end->name);
//	getchar();
	}
//	ft_printf("new_path->length = %d, new_path->output_forks = %d\n", new_path->length, new_path->output_fork);
//	ft_printf("lemin->top_paths = %p, &lemin->top_paths = %p\n", lemin->top_paths, &lemin->top_paths);
//	getchar();
	ft_add_path(&lemin->top_paths, new_path);
}

void		ft_del_other_links(t_lemin *lemin, t_path *surviving_path)
{
	t_path	*tmp_path;

	tmp_path = lemin->top_paths;
	while (tmp_path)
	{
		if (tmp_path != surviving_path)
			ft_cleaner_links(&tmp_path->begin, &lemin->top_links);
		tmp_path = tmp_path->next;
	}
//ft_printf("&lemin->top_paths = %p, lemin->top_paths = %p\n", &lemin->top_paths, lemin->top_paths);
//getchar();
	ft_del_paths(&lemin->top_paths);
//	ft_print_room_property(&lemin->top_rooms);
	ft_reset_io(&lemin->top_links);
	ft_io_count(&lemin->top_links);
	ft_del_dead_links(&lemin->top_links);//не уверена, нужно ли это здесь(то есть после очистки входных ветвлений могут снова образоваться мертвые концы, их нужно почистить)
}

void		ft_select_best_inlink(t_lemin *lemin)
{
	t_path	*tmp_path;
	t_path	*surviving_path;

	tmp_path = lemin->top_paths->next;
	surviving_path = lemin->top_paths;
	while (tmp_path)
	{
		if (tmp_path->output_fork == 1)
		{
			if (surviving_path->output_fork == 1 && tmp_path->length < surviving_path->length)
				surviving_path = tmp_path;
		}
		else if ((surviving_path->output_fork == 1) ||
			(tmp_path->length < surviving_path->length && surviving_path->output_fork == 0))
			surviving_path = tmp_path;
		tmp_path = tmp_path->next;
	}
	ft_del_other_links(lemin, surviving_path);
}

void		ft_find_max_bfs(t_lemin *lemin)
{
	t_link	*tmp;

	if (lemin->top_links)
	{
		tmp = lemin->top_links;
		while (tmp)
		{
			if (tmp->begin->bfslvl > lemin->max_bfs && tmp->begin->status != 2)
				lemin->max_bfs = tmp->begin->bfslvl;
			if (tmp->end->bfslvl > lemin->max_bfs && tmp->end->status != 2)
				lemin->max_bfs = tmp->end->bfslvl;
			tmp = tmp->next;
		}
	}
}

void		ft_del_inforks(t_lemin *lemin)
{
	int		cur_bfs;
	t_room	*tmp_room;
	t_link	*tmp_link;

//	ft_find_max_bfs(lemin);//найти максимальный bfs в графе
	cur_bfs = 1;//начинаем с 1 уровня(но можно со 2 в качестве оптимизации)
ft_printf("max_bfs = %d\n", lemin->max_bfs);
	while (cur_bfs <= lemin->max_bfs)
	{
		tmp_room = lemin->top_rooms;
		while (tmp_room)
		{
			if (tmp_room->inputs > 1 && tmp_room->bfslvl == cur_bfs)
			{
//				ft_select_best_inlink(tmp_room, lemin);
				tmp_link = lemin->top_links;
				while (tmp_link)
				{
					if (tmp_link->end == tmp_room)
//					{
//						ft_printf("input fork: [%s-%s]\n", tmp_link->begin->name, tmp_link->end->name);
						ft_create_es_path(tmp_link, lemin);
//					}
					tmp_link = tmp_link->next;
				}
				ft_select_best_inlink(lemin);
			}
			tmp_room = tmp_room->next;
		}
		cur_bfs++;
	}
}
