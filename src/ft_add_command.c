#include "ft_lemin.h"

void        start_and_end(t_lemin *lemin, char flag)
{
	if (flag == '1')
	{
		if (lemin->start)
//			ft_error("Комната старт уже существует");
			ft_error("ERROR: room is already exist\n");
		lemin->Output = ft_add_out(lemin->Output, lemin->line);
		free(lemin->line);
		if (get_next_line(lemin->fd, &lemin->line) == 0 && lemin->line[0] == '\0')
//			ft_error("Некорректные данные.");
			ft_error("ERROR: incorrect input data\n");
		lemin->flag_end_begin = 1;
        parse_room(lemin);
	}
	else
	{
		if (lemin->end)
//			ft_error("Комната end уже существует");
			ft_error("ERROR: room is already exist\n");
		lemin->Output = ft_add_out(lemin->Output, lemin->line);
		free(lemin->line);
		if (get_next_line(lemin->fd, &lemin->line) == 0 && lemin->line[0] == '\0')
//			ft_error("Некорректные данные.");
			ft_error("ERROR: incorrect input data\n");
        lemin->flag_end_begin = 2;
        parse_room(lemin);
	}
}

void        ft_parse_command(t_lemin *lemin, int i)
{
	if (lemin->num_of_ants && lemin->line[i] == '#')
	{
		if (!ft_strcmp(lemin->line, "##start"))
			start_and_end(lemin, '1');
		else if (!ft_strcmp(lemin->line, "##end"))
			start_and_end(lemin, '0');
		else
//			ft_error("Некорректная команда.");
			ft_error("ERROR: incorrect command\n");
	}
}

void        ft_error(char *error)
{
	ft_printf(error);
	exit(0);
}

void        free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
