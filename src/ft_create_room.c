#include "ft_lemin.h"

t_room	*ft_create_room(char *name, int x, int y)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room) * 1);
	if (!new)
		return (NULL);
	new->name = name;//под каждый name будет выделяться память
	new->status = 1;//по умолчанию это средняя вершина
	new->x = x;
	new->y = y;
	new->ant_number = -1;
	new->visited = 0;
	new->flag_v = 0;
	new->links_count = 0;
	new->neighbours = NULL;
	new->next_room = NULL;
	new->prev_room = NULL;
	new->next_in_list = NULL;
	return (new);
}

void	ft_delone_room(t_room **top_rooms, t_room *room)
{
	t_room	*tmp_prev;

	if (top_rooms && *top_rooms && room)
	{
//		if (room->neighbours)
//		{
//ft_printf("HERE %s->neighbours\n", room->name);
//ft_print_room_links(&room->neighbours);
			ft_lstdel(&room->neighbours, NULL);
//		}
		if (*top_rooms == room)//нужно удалить 1ю комнату
		{
//			ft_printf("DELETING FIRST ELEM\n");
			*top_rooms = (*top_rooms)->next_in_list;
		}
		else if (room->next_in_list != NULL)//средний элемент
		{
//			ft_printf("DELETING MIDDLE ELEM\n");
			tmp_prev = *top_rooms;
			while (tmp_prev->next_in_list != room)
				tmp_prev = tmp_prev->next_in_list;
			tmp_prev->next_in_list = room->next_in_list;
		}
		else//последний элемент
		{
//			ft_printf("DELETING LAST ELEM\n");
			tmp_prev = *top_rooms;
			while (tmp_prev->next_in_list->next_in_list)
				tmp_prev = tmp_prev->next_in_list;
			tmp_prev->next_in_list = NULL;
		}
		ft_del_room(&room);
	}
}

void	ft_del_room(t_room **room)
{
	if (room != NULL && *room)
	{
		ft_strdel(&((*room)->name));
		free(*room);
		*room = NULL;
	}
}

void	ft_del_rooms(t_room **head)
{
	t_room	*tmp;

	if (head != NULL && *head)
	{
		tmp = *head;
		while (tmp)
		{
			ft_lstdel(&(tmp->neighbours), NULL);
			tmp = tmp->next_in_list;
		}
		while ((*head)->next_in_list)
		{
			tmp = (*head)->next_in_list;
			ft_del_room(head);
			*head = tmp;
		}
		ft_del_room(head);
		*head = NULL;
	}
}
