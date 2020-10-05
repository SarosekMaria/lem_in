/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:38:10 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:50:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_visit(t_tree *node)
{
	if (node->room->status == 1 && node->room->next_room == NULL)
	{
		if (node->len > 0)
			node->room->visited = 1;
		else
			node->room->flag_v = 1;
	}
}

int			ft_intersect(t_room *src, t_room *dst)
{
	if ((src->next_room && src->next_room == dst) ||
		(dst->prev_room == NULL) ||
		(dst->prev_room == src))
		return (0);
	return (1);
}

int			ft_move_free(t_tree *node, t_room *dst)
{
	if ((node->len > 0 && dst->visited) ||
		(node->len == 0 && dst->flag_v) ||
		(node->room->prev_room != NULL && node->room->prev_room == dst) ||
		(node->intersection == dst) ||
		(node->intersection != NULL && node->room == node->intersection &&
		dst != node->room->next_room) ||
		(node->room->status == 0 && dst->prev_room == node->room) ||
		(dst->status == 0))
		return (0);
	return (1);
}

void		ft_reset_v(t_lemin *lemin)
{
	t_room	*tmp;

	tmp = lemin->top_rooms;
	while (tmp)
	{
		tmp->visited = 0;
		tmp->flag_v = 0;
		tmp = tmp->next_in_list;
	}
}
