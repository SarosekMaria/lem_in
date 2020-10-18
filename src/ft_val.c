/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:38:20 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 22:07:44 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void			check_input(t_lemin *lemin)
{
	int			i;

	i = 0;
	while (get_next_line(0, &lemin->line) > 0)
	{
		if (!lemin->num_of_ants && lemin->line[0] == '#')
			ft_error("ERROR: incorrect input data\n");
		if (!lemin->num_of_ants && lemin->line[0] != '#')
			is_digits(lemin);
		else if (lemin->line[0] == '#')
			ft_parse_command(lemin, 1);
		else if (check_room_or_link(lemin, 0))
			ft_error("ERROR: incorrect input data\n");
		if (!lemin->output)
			lemin->output = ft_create_out(lemin->line);
		else
			lemin->output = ft_add_out(lemin->output, lemin->line);
		free(lemin->line);
	}
	if (!start_end(lemin))
		ft_error("ERROR: no end or start\n");
	if (!lemin->top_links)
		ft_error("ERROR; incorrect input data\n");
}

void			is_digits(t_lemin *lemin)
{
	int			i;

	i = 0;
	if (lemin->line[0] == '\0')
		ft_error("ERROR: incorrect number of ants\n");
	while (lemin->line[i] != '\0')
	{
		if (!ft_isdigit(lemin->line[i]))
			ft_error("ERROR: incorrect number of ants\n");
		i++;
	}
	lemin->num_of_ants = ft_atoi(lemin->line);
	if (lemin->visual == 1)
		ft_printf("%d\n", lemin->num_of_ants);
}

int				isdigit_my(char **str, int i)
{
	char		*s;
	int			j;

	s = str[i];
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] < '0' || s[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int				check_room_or_link(t_lemin *lemin, int i)
{
	int			def;
	int			space;

	def = 0;
	space = 0;
	while (lemin->line[i] != '\0')
	{
		if (lemin->line[i] == '-')
			def++;
		else if (lemin->line[i] == ' ')
			space++;
		i++;
	}
	if (!def && space == 2)
		write_room(lemin);
	else if (!space && def > 0)
		write_link(lemin);
	else
		return (1);
	return (0);
}

int				start_end(t_lemin *lemin)
{
	int			flagend;
	int			flagstart;
	t_room		*c_r;

	flagend = 0;
	flagstart = 0;
	c_r = lemin->top_rooms;
	while (c_r)
	{
		if (c_r->status == 0)
			flagstart = 1;
		if (c_r->status == 2)
			flagend = 1;
		c_r = c_r->next_in_list;
	}
	if (!flagend || !flagstart)
		return (0);
	return (1);
}
