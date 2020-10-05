/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:36:51 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 18:49:26 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_zero_bfslvl(t_lemin *lemin, t_list **nodes)
{
	t_tree	*tree_node;

	tree_node = ft_new_tree_node(lemin->start);
	tree_node->len = 1;
	ft_lstadd(nodes, ft_lstnew(tree_node, sizeof(t_tree)));
}

t_path		*ft_bfs_tree(t_lemin *lemin)
{
	t_path	*path;
	t_list	*nodes;
	t_list	*next_nodes;

	ft_reset_v(lemin);
	nodes = NULL;
	ft_zero_bfslvl(lemin, &nodes);
	next_nodes = NULL;
	path = NULL;
	while (1)
	{
		path = ft_add_nodeslst(lemin, &nodes, &next_nodes);
		ft_del_treelvl(&nodes);
		if (path)
		{
			ft_del_treelvl(&next_nodes);
			return (path);
		}
		if (next_nodes == NULL)
			return (NULL);
		nodes = next_nodes;
		next_nodes = NULL;
	}
	return (path);
}

t_group		*ft_build_group(t_lemin *lemin, size_t max_num_of_path)
{
	t_path	*path;
	t_group	*best;
	t_group	*tmp;

	best = NULL;
	while (max_num_of_path > 0)
	{
		if (!(path = ft_bfs_tree(lemin)))
			break ;
		ft_path_modification(path);
		tmp = ft_create_group(lemin);
		ft_del_path(path);
		if (!best)
			best = tmp;
		else if (best->num_of_turns > tmp->num_of_turns)
		{
			ft_del_group(best);
			best = tmp;
		}
		else
			ft_del_group(tmp);
		max_num_of_path--;
	}
	return (best);
}
