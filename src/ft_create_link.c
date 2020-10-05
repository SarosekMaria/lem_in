/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:28:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 19:23:57 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_link		*ft_create_link(t_room *begin, t_room *end)
{
	t_link	*new;

	new = (t_link*)malloc(sizeof(t_link) * 1);
	if (!new)
		return (NULL);
	new->begin = begin;
	new->end = end;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_del_link(t_link **link)
{
	if (link != NULL && *link)
	{
		(*link)->begin = NULL;
		(*link)->end = NULL;
		(*link)->next = NULL;
		(*link)->prev = NULL;
		free(*link);
		(*link) = NULL;
	}
}

void		ft_del_links(t_link **head)
{
	t_link	*tmp;

	if (head != NULL && *head)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_link(head);
			*head = tmp;
		}
		ft_del_link(head);
		*head = NULL;
	}
}
