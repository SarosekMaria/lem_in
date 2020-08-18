#include "ft_lemin.h"

t_queue	*ft_new_qelem(t_room *room)
{
	t_queue	*new;

	new = (t_queue*)malloc(sizeof(t_queue));//попробовать сделать общую функцию очистки
	if (!new)
		return (NULL);
	new->room = room;
	new->next = NULL;
	return (new);
}

t_queue	*ft_enqueue(t_queue **tail, t_room *room, t_queue **head)
{
	t_queue	*new_tail;

	if (tail != NULL && *tail != NULL)
	{
		new_tail = ft_new_qelem(room);
		if (!new_tail)
			return (NULL);
		(*tail)->next = new_tail;
		*tail = new_tail;
	}
	else
	{
		new_tail = ft_new_qelem(room);
		if (!new_tail)
			return (NULL);
		*tail = new_tail;
		*head = *tail;
	}
	return (*tail);
}

t_room	*ft_dequeue(t_queue **head, t_queue **tail)
{
	t_room	*room;
	t_queue	*new_head;

	room = NULL;
	if (head != NULL && *head != NULL)
	{
		room = (*head)->room;
		if ((*head)->next)
		{
			new_head = (*head)->next;
			(*head)->next = NULL;
			ft_del_qelem(head);
			*head = new_head;
		}
		else
		{
			ft_del_qelem(head);
			*tail = NULL;
		}
	}
	return (room);
}

void	ft_del_qelem(t_queue **qelem)
{
	if (qelem != NULL)
	{
		free(*qelem);
		(*qelem) = NULL;
	}
}
