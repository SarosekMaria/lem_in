/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_ant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:56 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 20:01:25 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_distrib_ants(t_group *g, size_t num_of_ants)
{
	size_t	i;
	size_t	free_ants;

	free_ants = num_of_ants;
	while (free_ants > 0)
	{
		i = 0;
		while (i < g->num_of_paths - 1)
		{
			if (g->paths[i]->len + g->ants[i] <
					g->paths[i + 1]->len + g->ants[i + 1])
				break ;
			i++;
		}
		g->ants[i]++;
		free_ants--;
	}
}

void		ft_ants_to_first_rooms(t_lemin *lemin, t_group *g, size_t *ant_i)
{
	size_t	i;

	i = 0;
	while (*ant_i < lemin->num_of_ants && i < g->num_of_paths)
	{
		if (!(g->ants[i] > 0))
		{
			i++;
			continue ;
		}
		ft_add_ant(&lemin->head_ants, &lemin->tail_ants,
						ft_create_ant(g->paths[i]->top_fpath, *ant_i));
		(*ant_i)++;
		g->ants[i]--;
		i++;
	}
}

void		ft_move_ants_forward(t_lemin *lemin)
{
	t_ant	*tmp;

	tmp = lemin->head_ants;
	while (tmp && tmp->cur_location)
	{
		while (tmp && tmp->cur_location->room == lemin->end)
			ft_cleaner_ant(&tmp, &lemin->head_ants, &lemin->tail_ants);
		if (tmp && tmp->cur_location)
		{
			tmp->cur_location = tmp->cur_location->next;
			ft_printf("L%d-%s", tmp->i + 1, tmp->cur_location->room->name);
			if (tmp->cur_location->room == lemin->end)
				lemin->ants_at_the_end++;
			if (tmp->next)
				ft_printf(" ");
			tmp = tmp->next;
		}
	}
	if (lemin->head_ants && lemin->tail_ants)
		ft_printf("\n");
}

void		ft_manipulate_ant(t_lemin *lemin, t_group *g)
{
	size_t	ant_i;

	ant_i = 0;
	while (ant_i < lemin->num_of_ants)
	{
		ft_ants_to_first_rooms(lemin, g, &ant_i);
		ft_move_ants_forward(lemin);
	}
	while (lemin->head_ants != NULL)
		ft_move_ants_forward(lemin);
	if (lemin->ants_at_the_end != lemin->num_of_ants)
		ft_printf("ERROR: not all ants in the end!!!\n");
}
