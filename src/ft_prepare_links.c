#include "ft_lemin.h"

void		ft_reset_io(t_link **top_links)
{
	t_link	*tmp;

	if (top_links)
	{
		tmp = *top_links;
		while (tmp)
		{
			tmp->begin->inputs = 0;
			tmp->begin->outputs = 0;
			tmp->end->inputs = 0;
			tmp->end->outputs = 0;
			tmp = tmp->next;
		}
	}
}

void		ft_del_dead_links(t_link **top_links)
{
ft_printf("+++++++++FT_DEL_DEAD_LINKS+++++++++\n");
	t_link	*tmp;
	int		dead_end_exists;

	dead_end_exists = 1;
	if (top_links)
	{
		while (dead_end_exists)
		{
			tmp = *top_links;
			dead_end_exists = 0;
			while (tmp)
			{
				if ((tmp->begin->inputs == 0 &&//i == 0, o != 0, !start
					tmp->begin->outputs != 0 &&
					tmp->begin->status != 0) ||
					(tmp->begin->outputs == 0 &&//i != 0, o == 0, !end
					tmp->begin->inputs != 0 &&
					tmp->begin->status != 2) ||
					(tmp->end->inputs == 0 &&//i == 0, o != 0, !start
					tmp->end->outputs != 0 &&
					tmp->end->status != 0) ||
					(tmp->end->outputs == 0 &&//i != 0, o == 0, !end
					tmp->end->inputs != 0 &&
					tmp->end->status != 2))
				{
					ft_reset_io(top_links);
					ft_cleaner_links(&tmp, top_links);
					ft_io_count(top_links);
					dead_end_exists = 1;
				}
				if (tmp)//если элемент не последний
					tmp = tmp->next;
			}
		}
	}
}

void	ft_io_count(t_link **top_links)
{
	t_link	*tmp;

	if (top_links)
	{
		tmp = *top_links;
		while (tmp)
		{
			tmp->begin->outputs++;
			tmp->end->inputs++;
			tmp = tmp->next;
		}
	}
}

void	ft_align_links(t_link **top_links)
{
ft_printf("--------FT_ALIGN_LINKS-------\n");
	t_link	*tmp;
	t_room	*swap_tmp;

	tmp = *top_links;
	while (tmp)
	{
		if (tmp->begin->bfslvl > tmp->end->bfslvl)
		{
			swap_tmp = tmp->begin;
			tmp->begin = tmp->end;
			tmp->end = swap_tmp;
		}
		tmp = tmp->next;
	}
}
