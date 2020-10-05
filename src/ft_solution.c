/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assasin <assasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:01:25 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 12:44:41 by assasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static size_t	ft_max_paths(t_lemin *lemin)
{
	size_t		min;

	min = 0;
	if (lemin->start->links_count < lemin->end->links_count)
		min = lemin->start->links_count;
	else
		min = lemin->end->links_count;
	if (min > lemin->num_of_ants)
		min = lemin->num_of_ants;
	return (min);
}

int				ft_solution(t_lemin *lemin)
{
	size_t		max_num_of_paths;
	t_group		*new_group;

	max_num_of_paths = ft_max_paths(lemin);
	new_group = ft_build_group(lemin, max_num_of_paths);
	if (!new_group || !new_group->paths)
		return (-1);
	lemin->best_group = new_group;
	return (1);
}
