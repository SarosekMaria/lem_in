#include "ft_lemin.h"

void	ft_del_useless_links(t_link **top_links)
{
ft_printf("*******FT_DEL_USELESS_LINKS******\n");
	t_link	*tmp;

	tmp = *top_links;
	while(tmp)
	{
		if (tmp->begin->bfslvl == tmp->end->bfslvl ||
			tmp->begin->bfslvl == -1 || tmp->end->bfslvl == -1)
			ft_cleaner_links(&tmp, top_links);
		else
		tmp = tmp->next;
	}
}

void	ft_find_room_neighbour(int *number, t_link **top_links,
								t_queue **head, t_queue **tail)
{
	t_link	*tmp;

	tmp = *top_links;
	*number = (ft_dequeue(head, tail))->room_number;
	while (tmp)
	{
		if (tmp->begin->room_number == *number && tmp->end->bfslvl == -1)
		{
			tmp->end->bfslvl = tmp->begin->bfslvl + 1;
			ft_enqueue(tail, tmp->end, head);
		}
		else if (tmp->end->room_number == *number && tmp->begin->bfslvl == -1)
		{
			tmp->begin->bfslvl = tmp->end->bfslvl + 1;
			ft_enqueue(tail, tmp->begin, head);
		}
		tmp = tmp->next;
	}	
}

void	ft_bfs(t_lemin *lemin)
{
	t_queue	*head;
	t_queue	*tail;
	int		number;

	tail = ft_new_qelem(lemin->start);
	head = tail;
	ft_init_room_numbers(&lemin->top_rooms);
	number = 0;
	while (!(head == NULL && tail == NULL))
		ft_find_room_neighbour(&number, &lemin->top_links, &head, &tail);
/*проверка разметки bfs
t_room	*tmp;
tmp = *top_rooms;
while (tmp)
{
	ft_printf("name:%s\nbfslvl:%d\nstatus:%d\nnumber:%d\n", tmp->name, tmp->bfslvl, tmp->status,tmp->room_number);
	tmp = tmp->next;
	ft_printf("\n\n");
}
*/
	ft_del_useless_links(&lemin->top_links);
//	ft_print_links(top_links);//проверка удалены ли все бесполезные ссылки
	ft_align_links(&lemin->top_links);
//	ft_print_links(&lemin->top_links);//проверка удалены ли все бесполезные ссылки
	ft_io_count(&lemin->top_links);
//	ft_print_links(top_links);
	ft_del_dead_links(&lemin->top_links);//удаление ссылок, у которых output==0 или input==0
//	ft_print_links(&lemin->top_links);
//	ft_print_room_property(&lemin->top_rooms);//печать комнат со всеми свойствами
	ft_find_max_bfs(lemin);
	ft_del_inforks(lemin);
	ft_del_outforks(lemin);
	ft_print_room_property(&lemin->top_rooms);
	ft_print_links(&lemin->top_links);
	ft_form_path(lemin);
}
