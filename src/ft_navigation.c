/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_navigation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:59 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:46:26 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_tree		*ft_ret_navig_tostart(t_lemin *lemin, t_tree *node)
{
	t_tree	*new_node;
	t_room	*tmp;

	if (node->parent->room->next_room != NULL)
	{
		tmp = node->parent->room;
		while (tmp->prev_room->status != 0)
			tmp = tmp->prev_room;
		if (node->intersection == tmp)
			return (NULL);
		new_node = ft_tree_child(node, lemin->start);
		new_node = ft_tree_child(new_node, tmp);
		new_node->len++;
		return (new_node);
	}
	return (NULL);
}

t_path		*ft_complete_path(t_tree *node)
{
	t_path	*new_path;
	t_tree	*tmp;

	if (node->len > 0)
	{
		tmp = node;
		new_path = ft_create_path();
		while (tmp)
		{
			ft_addelem_path(new_path, tmp->room);
			tmp = tmp->parent;
		}
		return (new_path);
	}
	return (NULL);
}

t_tree		*ft_navigate(t_tree *node, t_room *dst)
{
	t_tree	*new_node;
	t_room	*intersect;
	int		len;

	if (!ft_move_free(node, dst))
		return (NULL);
	len = node->len;
	if (ft_intersect(node->room, dst))
	{
		len--;
		if (len < 0)
			return (NULL);
		intersect = dst;
	}
	else if (node->room->next_room && node->room->next_room != dst)
		intersect = NULL;
	else
		intersect = node->intersection;
	new_node = ft_tree_child(node, dst);
	new_node->len = len;
	new_node->intersection = intersect;
	return (new_node);
}
