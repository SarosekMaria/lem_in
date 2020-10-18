/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:35 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/05 21:57:51 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_path		*ft_add_node(t_lemin *lemin, t_tree *node, t_list **next_nodes)
{
	t_path	*path;
	t_tree	*new_node;
	t_list	*tmp;

	ft_visit(node);
	path = NULL;
	if (node && node->room->status == 2)
	{
		path = ft_complete_path(node);
		if (path)
			return (path);
		new_node = ft_ret_navig_tostart(lemin, node);
		if (new_node)
			ft_lstadd(next_nodes, ft_lstnew(new_node, sizeof(t_tree)));
		return (NULL);
	}
	tmp = node->room->neighbours;
	while (tmp)
	{
		new_node = ft_navigate(node, (t_room *)(tmp->content));
		if (new_node)
			ft_lstadd(next_nodes, ft_lstnew(new_node, sizeof(t_tree)));
		tmp = tmp->next;
	}
	return (path);
}

t_path		*ft_add_nodeslst(t_lemin *lemin, t_list **nodes,
											t_list **next_nodes)
{
	t_list	*tmp;
	t_path	*path;

	tmp = *nodes;
	while (tmp)
	{
		path = ft_add_node(lemin, (t_tree *)(tmp->content), next_nodes);
		if (path)
			return (path);
		tmp = tmp->next;
	}
	return (NULL);
}
