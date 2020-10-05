/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:38:20 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/02 18:38:21 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		ft_val_overflow(char *s)
{
	int	size;
	int	nb;

	if (ft_strlen(s) > 10)
		return (0);
	nb = ft_atoi(s);
	size = ft_strlen(s);
	if (nb == -1 && size != 2)
		return (0);
	return (1);
}
