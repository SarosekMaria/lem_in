#include "ft_lemin.h"

t_room				*ft_find_next_room(t_room *room, t_link **top_links)
{
	t_link			*tmp;

	if (top_links && *top_links)
	{
		tmp = *top_links;
		while (tmp)
		{
			if (tmp->begin == room)
				return (tmp->end);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

void				ft_move_ants_forward(t_lemin *lemin)
{
	t_ant			*tmp;

	if (lemin->head_ants)
	{
		tmp = lemin->head_ants;
		while (tmp)
		{
			tmp->cur_room->ant_number = -1;
			tmp->cur_room = ft_find_next_room(tmp->cur_room, &lemin->top_links);
//ft_printf("Next room for ant №%d is %s\n", tmp->i, tmp->cur_room->name);
//И вот здесь выводить в какую комнату пошел муравей №i
			ft_printf("L%u-%s ", tmp->i , tmp->cur_room->name);
			tmp->cur_room->ant_number = tmp->i;
			if (tmp->cur_room == lemin->end)
			{
//				ft_printf("ANT №%d reaches THE END!!!\n", tmp->i);
				ft_cleaner_ants(&tmp, &lemin->head_ants, &lemin->tail_ants);
				lemin->ants_at_the_end++;
			}
			else
				tmp = tmp->next;
		}
	}
}

unsigned int		ft_sum_difs(t_path **top_paths, t_path *cur_path)
{
	t_path			*tmp;
	unsigned int	sum_difs;

	sum_difs = 0;
	if (top_paths && *top_paths && cur_path)
	{
		tmp = *top_paths;
		while (tmp && tmp != cur_path)
		{
//ft_printf("HERE\n");
			sum_difs += cur_path->length - tmp->length;
			tmp = tmp->next;
		}
	}
//	ft_printf("sum_difs = %u\n", sum_difs);
	return (sum_difs);
}

void				ft_manipulate_ants(t_lemin *lemin)
{
	unsigned int	i;
	int				count_path;
	t_path			*cur_path;//переборка путей, пока не отправим в путь число муравьев = общему количеству путей

	i = 0;
	while (i < lemin->number_of_ants)
	{
//ft_printf("lemin->number_of_ants = %d\n", lemin->number_of_ants);
		count_path = lemin->quantity_path;
		cur_path = lemin->top_paths;
		while (count_path > 0 && i < lemin->number_of_ants)
		{
//			ft_printf("i = %d, count_path = %d, cur_path->length = %d\n", i, count_path, cur_path->length);
			if (lemin->number_of_ants - i <= ft_sum_difs(&lemin->top_paths, cur_path))
			{
//				i++;
//				ft_printf("Условие не удовлетворилось!\n");
				break ;
			//	cur_path = lemin->top_paths;
			}
//			ft_printf("cur_path->begin->begin->name - cur_path->begin->end->name:%s-%s\n", cur_path->begin->begin->name, cur_path->begin->end->name);
			cur_path->begin->end->ant_number = i;
			ft_add_ant(&lemin->head_ants, &lemin->tail_ants, ft_create_ant(i, cur_path->begin->end));
			ft_printf("L%u-%s ", i, cur_path->begin->end->name);
			i++;
			if (cur_path->next)
				cur_path = cur_path->next;
			else
				cur_path = lemin->top_paths;
			count_path--;
			//Вот здесь на каждой итерации выводить в какую комнату пошел муравей под №i
		}
		if (i != 0)
			ft_printf("\n");
		ft_move_ants_forward(lemin);
//		ft_printf("\n");
	}
	while (lemin->ants_at_the_end < lemin->number_of_ants)
	{
		ft_printf("\n");
		ft_move_ants_forward(lemin);
	}
	ft_printf("\n");
	ft_printf("ants at start = %d, ants at end = %d\n", lemin->number_of_ants, lemin->ants_at_the_end);
}
