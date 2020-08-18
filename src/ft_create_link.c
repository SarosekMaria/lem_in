#include "ft_lemin.h"

t_link	*ft_create_link(t_room *begin, t_room *end)
{
	t_link	*new;

	new = (t_link*)malloc(sizeof(t_link) * 1);
	if (!new)
		return (NULL);
	new->begin = begin;
	new->end = end;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_del_link(t_link **link)
{
	if (link != NULL)
	{
		(*link)->begin = NULL;
		(*link)->end = NULL;
		(*link)->next = NULL;
		(*link)->prev = NULL;
		free(*link);
		(*link) = NULL;
	}
}

void	ft_del_links(t_link **head)
{
	t_link	*tmp;

	if (head != NULL)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_link(head);
			*head = tmp;
		}
		ft_del_link(head);
		*head = NULL;
	}
}

void	ft_cleaner_links(t_link **tmp, t_link **top_links)
{
	t_link  *tmp_prev;

	if ((*tmp)->prev == NULL)//если элемент стоит первым в списке
	{
ft_printf("FT_CLEANER: element is the first\n");
		((*tmp)->next)->prev = NULL;
		*top_links = (*tmp)->next;
		ft_del_link(tmp);
		*tmp = *top_links;
	}
	else if ((*tmp)->prev != NULL && (*tmp)->next != NULL)//элемент между др. двумя
	{
ft_printf("FT_CLEANER: element is inner\n");
		((*tmp)->prev)->next = (*tmp)->next;
		((*tmp)->next)->prev = (*tmp)->prev;
		tmp_prev = (*tmp)->prev;
		ft_del_link(tmp);
		*tmp = tmp_prev;
	}
	else if ((*tmp)->next == NULL)//последний элемент в списке
	{
ft_printf("FT_CLEANER: element is the last\n");
		((*tmp)->prev)->next = NULL;
		ft_del_link(tmp);
	}
}
