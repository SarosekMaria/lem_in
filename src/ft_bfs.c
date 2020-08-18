#include "ft_lemin.h"

void	ft_del_useless_links(t_link **top_links)
{
	t_link	*tmp;
//	t_link	*tmp_prev;

	tmp = *top_links;
	while(tmp)
	{
		if (tmp->begin->bfslvl == tmp->end->bfslvl ||
			tmp->begin->bfslvl == -1 || tmp->end->bfslvl == -1)
		{
			ft_cleaner_links(&tmp, top_links);
/*			if (tmp->prev == NULL)//если элемент стоит первым в списке
			{
				(tmp->next)->prev = NULL;
				*top_links = tmp->next;
				ft_del_link(&tmp);
				tmp = *top_links;
			}
			else if (tmp->prev != NULL && tmp->next != NULL)//элемент находится между др. двумя
			{
				(tmp->prev)->next = tmp->next;
				(tmp->next)->prev = tmp->prev;
				tmp_prev = tmp->prev;
				ft_del_link(&tmp);
				tmp = tmp_prev;
			}
			else if (tmp->next == NULL)//последний элемент в списке
			{
				(tmp->prev)->next = NULL;
				ft_del_link(&tmp);
			}*/
		}
		else
		tmp = tmp->next;
	}
}

void	ft_find_room_neighbour(int *number, t_link **top_links, t_queue **head, t_queue **tail)
{
	t_link	*tmp;

	tmp = *top_links;
	*number = (ft_dequeue(head, tail))->room_number;
//ft_printf("number = %d\n", *number);
	while (tmp)
	{
		if (tmp->begin->room_number == *number && tmp->end->bfslvl == -1)
		{
//ft_printf("begin = %s, end = %s\n", tmp->begin->name, tmp->end->name);
			tmp->end->bfslvl = tmp->begin->bfslvl + 1;
			ft_enqueue(tail, tmp->end, head);
		}
		else if (tmp->end->room_number == *number && tmp->begin->bfslvl == -1)
		{
//ft_printf("begin = %s, end = %s\n", tmp->begin->name, tmp->end->name);
			tmp->begin->bfslvl = tmp->end->bfslvl + 1;
			ft_enqueue(tail, tmp->begin, head);
		}
		tmp = tmp->next;
	}	
}

/*t_room	*ft_find_start(t_room **top_rooms)
{
	t_room	*tmp;

	tmp = *top_rooms;
	while (tmp)
	{
		if (tmp->status == 0)//то есть это старт
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}*/

void	ft_bfs(t_lemin *lemin)
{
	t_queue	*head;
	t_queue	*tail;
	int	number;

//	tail = ft_new_qelem(ft_find_start(lemin->top_rooms));
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
//	ft_print_links(top_links);//проверка удалены ли все бесполезные ссылки
	ft_io_count(&lemin->top_links);
//	ft_print_links(top_links);
	ft_del_dead_links(&lemin->top_links);//удаление ссылок, у которых output==0 или input==0
//	ft_print_links(top_links);
//	ft_print_room_property(top_rooms);//печать комнат со всеми свойствами
//	ft_del_inforks(lemin);
}
