#include "ft_lemin.h"

void	ft_init_room_numbers(t_room **head)
{
	t_room	*tmp;
	int	number;

	number = 0;
	if (head != NULL)
	{
		tmp = *head;
		while (tmp)
		{
			tmp->room_number = number;
			tmp = tmp->next;
			number++;
		}
	}
}

t_room	*ft_create_room(char *name, int x, int y)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room) * 1);
	if (!new)
		return (NULL);
	new->name = name;//под каждый name будет выделяться память
	new->room_number = -1;
	new->bfslvl = -1;
	new->status = 1;//по умолчанию это средняя вершина
	new->inputs = 0;
	new->outputs = 0;
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
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
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_room(head);
			*head = tmp;
		}
		ft_del_room(head);
		*head = NULL;
	}
}
