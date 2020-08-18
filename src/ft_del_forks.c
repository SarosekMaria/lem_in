#include "ft_lemin.h"
/*
void		ft_select_best_inlink(t_room *start, t_room *end)
{
	
}

int			ft_find_max_bfs(t_link **top_links)
{
	t_link	*tmp;
	int	max_bfs;

	max_bfs = 0;
	if (top_links)
	{
		tmp = *top_links
		while (tmp)
		{
			if (tmp->begin->bfslvl > max_bfs && tmp->begin->status != 2)
				max_bfs = tmp->begin->bfslvl;
			if (tmp->end->bfslvl > max_bfs && tmp->end->status != 2)
				max_bfs = tmp->end->bfslvl;
			tmp = tmp->next;
		}
	}
	return (max_bfs);
}

void		ft_del_inforks(t_room **top_rooms, **top_links)
{
	int		cur_bfs;
	int		max_bfs;
	t_room	*tmp_room;

	max_bfs = ft_find_max_bfs(top_links);//найти максимальный bfs в графе(оптимизация - м/о его уже где-то хранить, вместе с *start и *end (например, t_lemin))
	cur_bfs = 1;//начинаем с 1 уровня(но можно попробовать со 2 в качестве оптимизации)
	while (cur_bfs <= max_bfs)
	{
		tmp = *top_rooms;
		while (tmp)
		{
			if (tmp->inputs > 1 && tmp->bfslvl == cur_bfs)
			{
				ft_select_best_inlink();
				ft_del_other_links();
			}
		}
		cur_bfs++;
	}
}*/
