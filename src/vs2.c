/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:08:36 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/30 22:08:36 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void			free_strv(char **str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_linkv			*ft_create_linkv(t_roomv *begin, t_roomv *end)
{
	t_linkv		*new;

	new = (t_linkv*)malloc(sizeof(t_linkv) * 1);
	if (!new)
		return (NULL);
	new->begin = begin;
	new->end = end;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			ft_del_linkv(t_linkv **link)
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

void			ft_del_linksv(t_linkv **head)
{
	t_linkv		*tmp;

	if (head != NULL && *head)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			ft_del_linkv(head);
			*head = tmp;
		}
		ft_del_linkv(head);
		*head = NULL;
	}
}

void			add_list_linksv(t_linkv **top_links, t_linkv *link)
{
	link->next = *top_links;
	(*top_links)->prev = link;
	*top_links = link;
}
