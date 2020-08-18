#include "ft_lemin.h"

/*void	ft_create_example(t_room *top_rooms, t_link *top_links)
{
	t_room	*a;
	t_room	*b;
	t_room	*c;
	t_room	*d;
	t_room	*e;
	t_room	*f;
	t_room	*start;
	t_room	*end;
	t_link	*first;
	t_link	*second;
	t_link	*third;
	t_link	*fourth;
	t_link	*fifth;
	t_link	*sixth;
	t_link	*seventh;
	t_link	*eighth;
	t_link	*ninth;


	char	*name_a;
	char	*name_b;
	char	*name_c;
	char	*name_d;
	char	*name_e;
	char	*name_f;
	char	*name_start;
	char	*name_end;

	name_a = ft_strnew(1);
	name_b = ft_strnew(1);
	name_c = ft_strnew(1);
	name_d = ft_strnew(1);
	name_e = ft_strnew(1);
	name_f = ft_strnew(1);
	name_start = ft_strnew(5);
	name_end = ft_strnew(3);

	name_a[0] = 'a';
	name_b[0] = 'b';
	name_c[0] = 'c';
	name_d[0] = 'd';
	name_e[0] = 'e';
	name_f[0] = 'f';

	name_start[0] = 's';
	name_start[1] = 't';
	name_start[2] = 'a';
	name_start[3] = 'r';
	name_start[4] = 't';
	name_start[5] = '\0';

	name_end[0] = 'e';
	name_end[1] = 'n';
	name_end[2] = 'd';
	name_end[3] = '\0';

	a = ft_create_room(name_a, 0, 0);
	b = ft_create_room(name_b, 0, 0);
	c = ft_create_room(name_c, 0, 0);
	d = ft_create_room(name_d, 0, 0);
	e = ft_create_room(name_e, 0, 0);
	f = ft_create_room(name_f, 0, 0);
	start = ft_create_room(name_start, 0, 0);
	end = ft_create_room(name_end, 0, 0);

	start->status = 0;//не забыть сразу указать особый статус для start и end
	end->status = 2;

	start->bfslvl = 0;//не забыть указать при парсинге bfslvl
	end->bfslvl = MAX_INT;

	c->next = start;
	start->next = end;
	end->next = d;
	d->next = a;
	a->next = b;
	b->next = e;
	e->next = f;

	first = ft_create_link(start, a);
	second = ft_create_link(c, d);
	third = ft_create_link(b, d);
	fourth = ft_create_link(a, e);
	fifth = ft_create_link(f, e);
	sixth = ft_create_link(end, f);
	seventh = ft_create_link(a, b);
	eighth = ft_create_link(b, end);
	ninth = ft_create_link(c, start);

	first->next = second;
	second->next = third;
	second->prev = first;
	third->next = fourth;
	third->prev = second;
	fourth->next = fifth;
	fourth->prev = third;
	fifth->next = sixth;
	fifth->prev = fourth;
	sixth->next = seventh;
	sixth->prev = fifth;
	seventh->next = eighth;
	seventh->prev = sixth;
	eighth->next = ninth;
	eighth->prev = seventh;
	ninth->prev = eighth;

	top_rooms = c;
	top_links = first;
}*/

int main()
{
	t_lemin	*lemin;

	lemin = ft_init_lemin();
//	ft_create_example(lemin->top_rooms, lemin->top_links);
//после парсинга получаю адрес указателя на голову списка комнат и адрес указателя на голову списка ссылок
	t_room	*a;
	t_room	*b;
	t_room	*c;
	t_room	*d;
	t_room	*e;
	t_room	*f;
	t_room	*start;
	t_room	*end;

	char	*name_a;
	char	*name_b;
	char	*name_c;
	char	*name_d;
	char	*name_e;
	char	*name_f;
	char	*name_start;
	char	*name_end;

	t_link	*first;
	t_link	*second;
	t_link	*third;
	t_link	*fourth;
	t_link	*fifth;
	t_link	*sixth;
	t_link	*seventh;
	t_link	*eighth;
	t_link	*ninth;

	ft_printf("There would be validation\n");
	ft_printf("And there would be parsing\n");	
	
	name_a = ft_strnew(1);
	name_b = ft_strnew(1);
	name_c = ft_strnew(1);
	name_d = ft_strnew(1);
	name_e = ft_strnew(1);
	name_f = ft_strnew(1);
	name_start = ft_strnew(5);
	name_end = ft_strnew(3);

	name_a[0] = 'a';
	name_b[0] = 'b';
	name_c[0] = 'c';
	name_d[0] = 'd';
	name_e[0] = 'e';
	name_f[0] = 'f';

	name_start[0] = 's';
	name_start[1] = 't';
	name_start[2] = 'a';
	name_start[3] = 'r';
	name_start[4] = 't';
	name_start[5] = '\0';

	name_end[0] = 'e';
	name_end[1] = 'n';
	name_end[2] = 'd';
	name_end[3] = '\0';

	a = ft_create_room(name_a, 0, 0);
	b = ft_create_room(name_b, 0, 0);
	c = ft_create_room(name_c, 0, 0);
	d = ft_create_room(name_d, 0, 0);
	e = ft_create_room(name_e, 0, 0);
	f = ft_create_room(name_f, 0, 0);
	start = ft_create_room(name_start, 0, 0);
	end = ft_create_room(name_end, 0, 0);

	start->status = 0;//не забыть сразу указать особый статус для start и end
	end->status = 2;

	start->bfslvl = 0;//не забыть указать при парсинге bfslvl
	end->bfslvl = MAX_INT;

	c->next = start;
	start->next = end;
	end->next = d;
	d->next = a;
	a->next = b;
	b->next = e;
	e->next = f;

	first = ft_create_link(start, a);
	second = ft_create_link(c, d);
	third = ft_create_link(b, d);
	fourth = ft_create_link(a, e);
	fifth = ft_create_link(f, e);
	sixth = ft_create_link(end, f);
	seventh = ft_create_link(a, b);
	eighth = ft_create_link(b, end);
	ninth = ft_create_link(c, start);

	first->next = second;
	second->next = third;
	second->prev = first;
	third->next = fourth;
	third->prev = second;
	fourth->next = fifth;
	fourth->prev = third;
	fifth->next = sixth;
	fifth->prev = fourth;
	sixth->next = seventh;
	sixth->prev = fifth;
	seventh->next = eighth;
	seventh->prev = sixth;
	eighth->next = ninth;
	eighth->prev = seventh;
	ninth->prev = eighth;

	lemin->start = start;
	lemin->end = end;
	lemin->top_rooms = c;
	lemin->top_links = first;

	ft_print_rooms(&(lemin->top_rooms));
	ft_print_links(&(lemin->top_links));
	
	ft_bfs(lemin);
	
//	ft_del_rooms(&(lemin->top_rooms));
//	ft_del_links(&(lemin->top_links));
	ft_del_lemin(&lemin);
	return (0);
}
