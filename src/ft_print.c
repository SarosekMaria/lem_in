#include "ft_lemin.h"

//file for printing rooms and links

void	ft_print_rooms(t_room **head)
{
	t_room	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("%s ", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
}

void	ft_print_room_property(t_room **top_rooms)
{
	t_room	*tmp;

	if (top_rooms)
	{
		tmp = *top_rooms;
		while (tmp)
		{
			ft_printf("name:%s\nnumber:%d\nbfslvl:%d\nstatus:%d\ninputs:%d\noutputs:%d\n\n",tmp->name, tmp->room_number, tmp->bfslvl,tmp->status, tmp->inputs, tmp->outputs);
			tmp = tmp->next;
		}
	}
}

void	ft_print_links(t_link **head)
{
	t_link	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		ft_printf("%s-%s\n", tmp->begin->name, tmp->end->name);
		tmp = tmp->next;
	}
	ft_printf("%s-%s\n\n", tmp->begin->name, tmp->end->name);
	while (tmp)
	{
		ft_printf("%s-%s\n", tmp->begin->name, tmp->end->name);
		tmp = tmp->prev;
	}	
	ft_printf("\n");
}