#include "ft_lemin.h"

void		ft_add_ant(t_ant **head_ants, t_ant **tail_ants, t_ant *ant)
{//добавляем муравьев в конец списка
	if (head_ants && tail_ants)
	{
//ft_printf("Adding ants!\n");
		if (*head_ants == NULL && *tail_ants == NULL)//если в списке муравьев еще нет элементов
		{
//ft_printf("THE FIRST ANT COME'S!!!\n");
			*head_ants = ant;
			*tail_ants = *head_ants;
		}
		else if (*tail_ants != NULL)//в списке уже есть хотя бы один муравей
		{
			(*tail_ants)->next = ant;
			ant->prev = *tail_ants;
			*tail_ants = ant;
		}
	}
//ft_printf("head->ant = %d, tail_ant = %d\n", (*head_ants)->i,(*tail_ants)->i);
}

t_ant		*ft_create_ant(int index, t_room *cur_room)
{
	t_ant	*new;

	new = (t_ant*)malloc(sizeof(t_ant) * 1);
	if (!new)
		return (NULL);
	new->cur_room = cur_room;
	new->i = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_del_ant(t_ant **ant)
{
	if (ant && *ant)
	{
		(*ant)->cur_room = NULL;
		(*ant)->i = 0;
		(*ant)->next = NULL;
		(*ant)->prev = NULL;
		free(*ant);
		*ant = NULL;
	}
}

void		ft_del_ants(t_ant **top_ants)
{
	t_ant	*tmp;

	if (top_ants && *top_ants)
	{
		while ((*top_ants)->next)
		{
			tmp = (*top_ants)->next;
			ft_del_ant(top_ants);
			*top_ants = tmp;
		}
		ft_del_ant(top_ants);
		*top_ants = NULL;
	}
}

void		ft_cleaner_ants(t_ant **tmp, t_ant **head_ants, t_ant **tail_ants)
{
 //   t_ant	*tmp_prev;
	t_ant	*tmp_next;

	if ((*tmp)->prev == NULL && (*tmp)->next != NULL)//если элемент стоит первым в списке(эл-т не единственный, то есть существует следующий)
	{
		((*tmp)->next)->prev = NULL;
		*head_ants = (*tmp)->next;
		ft_del_ant(tmp);
		*tmp = *head_ants;
	}
	else if ((*tmp)->prev == NULL && (*tmp)->next == NULL)//если эл-т единственный
	{
//ft_printf("Я ПОСЛЕДНИЙ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		(*head_ants) = NULL;
		(*tail_ants) = NULL;
		ft_del_ant(tmp);
	}
	else if ((*tmp)->prev != NULL && (*tmp)->next != NULL)//элемент между др. двумя
	{
		((*tmp)->prev)->next = (*tmp)->next;
		((*tmp)->next)->prev = (*tmp)->prev;
		tmp_next = (*tmp)->next;
		ft_del_ant(tmp);
		*tmp = tmp_next;
	}
	else if ((*tmp)->next == NULL)//последний элемент в списке
	{
		(*tail_ants) = (*tail_ants)->prev;
		((*tmp)->prev)->next = NULL;
		ft_del_ant(tmp);
	}
}
