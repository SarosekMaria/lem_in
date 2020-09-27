#include "ft_lemin.h"

void		check_input(t_lemin *lemin)
{
    int i;

//	lemin->fd = open("map.txt", O_RDONLY);
//	lemin->fd = open("bs.txt", O_RDONLY);
//	lemin->fd = open("map_medium.txt", O_RDONLY);
	lemin->fd = 0;
    i = 0;
	while (get_next_line(lemin->fd, &lemin->line) > 0)
	{
		if (!lemin->num_of_ants && lemin->line[0] == '#')
			ft_error("ERROR: incorrect input data\n");
		if (!lemin->num_of_ants && lemin->line[0] != '#')
			is_digits(lemin);
		else if (lemin->line[0] == '#')
			ft_parse_command(lemin, 1);
		else if (check_room_or_link(lemin, 0))
		{
//			ft_error("некорректне данные1");
			ft_error("ERROR: incorrect input data\n");
		}
		if (!lemin->Output)
			lemin->Output = ft_create_out(lemin->line);
		else
			lemin->Output = ft_add_out(lemin->Output, lemin->line);
		free(lemin->line);
	}
	if (!start_end(lemin))
//		ft_error("no end or start");
		ft_error("ERROR: no end or start\n");
	if (!lemin->top_links)
//		ft_error("некорректне данные2");
		ft_error("ERROR; incorrect input data\n");
	close(lemin->fd);
}

void		is_digits(t_lemin *lemin)
{
	int i;

	i = 0;
	if (lemin->line[0] == '\0')
//		ft_error("Некорректное колличество муравьев.");
		ft_error("ERROR: incorrect number of ants\n");
	while (lemin->line[i] != '\0')
	{
		if (!ft_isdigit(lemin->line[i]))
//			ft_error("Некорректное колличество муравьев.");
			ft_error("ERROR: incorrect number of ants\n");
		i++;
	}
	lemin->num_of_ants = ft_atoi(lemin->line);
}

int			isdigit_my(char **str, int i)
{
	char	*s;
	int		j;

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

int			check_room_or_link(t_lemin *lemin, int i)
{
	int	def;
	int	space;

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
	else if (!space && def >0)
		write_link(lemin);
	else
		return (1);
	return (0);
}

int			start_end(t_lemin *lemin)
{
	int flagEnd;
	int flagStart;

	flagEnd = 0;
	flagStart = 0;
	t_room *c_r = lemin->top_rooms;
	while (c_r)
	{
		if(c_r->status == 0)
			flagStart = 1;
		if(c_r->status == 2)
			flagEnd = 1;
		c_r=c_r->next_in_list;
	}
	if(!flagEnd || !flagStart)
		return(0);
	return (1);
}
