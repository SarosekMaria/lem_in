/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:38:02 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 20:18:05 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_swap(t_path **path1, t_path **path2)
{
	t_path	*tmp;

	tmp = *path1;
	*path1 = *path2;
	*path2 = tmp;
}

void		ft_sortarr_paths(t_path **paths, size_t size)
{
	size_t	i;
	size_t	j;
	int		f_swap;

	i = 0;
	while (i < size)
	{
		j = 0;
		f_swap = 1;
		while (j < size - i - 1)
		{
			if (paths[j]->len > paths[j + 1]->len)
			{
				f_swap = 0;
				ft_swap(&paths[j], &paths[j + 1]);
			}
			j++;
		}
		if (f_swap)
			return ;
		i++;
	}
}

void		ft_del_path(t_path *path)
{
	t_fpath	*tmp;

	tmp = path->top_fpath;
	while (tmp)
	{
		path->top_fpath = path->top_fpath->next;
		free(tmp);
		tmp = NULL;
		tmp = path->top_fpath;
	}
	path->len = 0;
	free(path);
	path = NULL;
}
