/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:46 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:42:50 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_del_node(t_tree *node)
{
	t_tree	*tmp;
	t_tree	*del;

	tmp = node;
	while (tmp && tmp->num_of_childs == 0)
	{
		del = tmp;
		if (tmp->parent)
			tmp->parent->num_of_childs--;
		tmp = tmp->parent;
		free(del);
		del = NULL;
	}
}

void		ft_del_treelvl(t_list **nodes)
{
	while (*nodes)
	{
		ft_del_node((t_tree *)((*nodes)->content));
		ft_lstdelone(nodes, NULL);
	}
}

t_tree		*ft_tree_child(t_tree *node, t_room *dst)
{
	t_tree	*new_node;

	new_node = ft_new_tree_node(dst);
	if (!new_node)
		return (NULL);
	node->num_of_childs++;
	new_node->parent = node;
	new_node->intersection = node->intersection;
	new_node->len = node->len;
	return (new_node);
}

t_tree		*ft_new_tree_node(t_room *room)
{
	t_tree	*new_tree_node;

	new_tree_node = (t_tree *)malloc(sizeof(t_tree) * 1);
	if (!new_tree_node)
		return (NULL);
	new_tree_node->room = room;
	new_tree_node->num_of_childs = 0;
	new_tree_node->intersection = NULL;
	new_tree_node->parent = NULL;
	new_tree_node->len = 0;
	return (new_tree_node);
}
