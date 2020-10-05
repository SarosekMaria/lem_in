/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:10:18 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 20:10:27 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_print_fpath(t_fpath **top_fpath)
{
	t_fpath	*tmp;

	if (top_fpath && *top_fpath)
	{
		tmp = *top_fpath;
		ft_printf("Fpath:");
		while (tmp)
		{
			ft_printf("%s ", tmp->room->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

void	ft_print_path(t_path *path)
{
	ft_printf("len: %u\n", path->len);
	ft_print_fpath(&path->top_fpath);
}
