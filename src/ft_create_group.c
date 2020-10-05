/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:37:28 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:08:08 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_del_group(t_group *group)
{
	size_t	i;

	if (group != NULL)
	{
		i = 0;
		while (i < group->num_of_paths)
		{
			ft_del_path(group->paths[i]);
			i++;
		}
		free(group->paths);
		free(group->ants);
		group->paths = NULL;
		group->ants = NULL;
		group->num_of_paths = 0;
		group->num_of_turns = 0;
		free(group);
		group = NULL;
	}
}

void		ft_count_turns(t_group *group)
{
	size_t	i;
	size_t	current;

	i = 0;
	while (i < group->num_of_paths)
	{
		if (group->ants[i] > 0)
		{
			current = group->ants[i] + group->paths[i]->len - 1;
			if (current > group->num_of_turns)
				group->num_of_turns = current;
		}
		i++;
	}
}

t_group		*ft_create_group(t_lemin *lemin)
{
	t_group	*new_g;
	size_t	i;

	new_g = (t_group *)malloc(sizeof(t_group) * 1);
	if (!new_g)
		return (NULL);
	new_g->num_of_paths = ft_count_gpaths(lemin->start);
	new_g->ants = (int *)malloc(sizeof(int) * new_g->num_of_paths);
	i = 0;
	while (i < new_g->num_of_paths)
	{
		new_g->ants[i] = 0;
		i++;
	}
	new_g->paths = (t_path **)malloc(sizeof(t_path *) * new_g->num_of_paths);
	ft_create_gpaths(lemin->start, new_g);
	ft_sortarr_paths(new_g->paths, new_g->num_of_paths);
	ft_distrib_ants(new_g, lemin->num_of_ants);
	new_g->num_of_turns = 0;
	ft_count_turns(new_g);
	return (new_g);
}
