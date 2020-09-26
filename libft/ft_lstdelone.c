/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assasin <assasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:17:08 by sassassi          #+#    #+#             */
/*   Updated: 2020/09/26 10:04:02 by assasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	
	if (alst != NULL && *alst != NULL)
	{
		tmp = (*alst)->next;
		if (del)
			(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
}
