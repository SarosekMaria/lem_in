#include "ft_lemin.h"

int main()
{
	t_lemin	*lemin;

	lemin = ft_init_lemin();
ft_printf("±±±±±±± AT THE begin quantity_path = %d\n", lemin->quantity_path);
//после парсинга получаю указатель на голову списка комнат и указатель на голову списка ссылок
	t_room	*r0;
	t_room	*r1;
	t_room	*r2;
	t_room	*r3;
	t_room	*r4;
	t_room	*r5;
	t_room	*r6;
	t_room	*r7;
	t_room	*r8;
	t_room	*r9;
	t_room	*r10;
	t_room	*r11;
	t_room	*r12;
	t_room	*r13;
	t_room	*r14;
	t_room	*r15;

	char	*name_r0;
	char	*name_r1;
	char	*name_r2;
	char	*name_r3;
	char	*name_r4;
	char	*name_r5;
	char	*name_r6;
	char	*name_r7;
	char	*name_r8;
	char	*name_r9;
	char	*name_r10;
	char	*name_r11;
	char	*name_r12;
	char	*name_r13;
	char	*name_r14;
	char	*name_r15;

	t_link	*first;
	t_link	*second;
	t_link	*third;
	t_link	*fourth;
	t_link	*fifth;
	t_link	*sixth;
	t_link	*seventh;
	t_link	*eighth;
	t_link	*ninth;
	t_link	*tenth;
	t_link	*eleventh;
	t_link	*twelfth;
	t_link	*thirteenth;
	t_link	*fourteenth;
	t_link	*fifteenth;
	t_link	*sixteenth;
	t_link	*seventeenth;
	t_link	*eighteenth;
	t_link	*ninteenth;
	t_link	*twentienth;

	ft_printf("There would be validation\n");
	ft_printf("And there would be parsing\n");	
	
	name_r0 = ft_strnew(1);
	name_r1 = ft_strnew(1);
	name_r2 = ft_strnew(1);
	name_r3 = ft_strnew(1);
	name_r4 = ft_strnew(1);
	name_r5 = ft_strnew(1);
	name_r6 = ft_strnew(1);
	name_r7 = ft_strnew(1);
	name_r8 = ft_strnew(1);
	name_r9 = ft_strnew(1);
	name_r10 = ft_strnew(2);
	name_r11 = ft_strnew(2);
	name_r12 = ft_strnew(2);
	name_r13 = ft_strnew(2);
	name_r14 = ft_strnew(2);
	name_r15 = ft_strnew(2);

	name_r0[0] = 's';
	name_r1[0] = '1';
	name_r2[0] = '2';
	name_r3[0] = '3';
	name_r4[0] = '4';
	name_r5[0] = '5';
	name_r6[0] = '6';
	name_r7[0] = '7';
	name_r8[0] = '8';
	name_r9[0] = 'e';
	name_r10[0] = '1';
	name_r10[1] = '0';
	name_r11[0] = '1';
	name_r11[1] = '1';
	name_r12[0] = '1';
	name_r12[1] = '2';
	name_r13[0] = '1';
	name_r13[1] = '3';
	name_r14[0] = '1';
	name_r14[1] = '4';
	name_r15[0] = '1';
	name_r15[1] = '5';

	r0 = ft_create_room(name_r0, 0, 0);
	r1 = ft_create_room(name_r1, 0, 0);
	r2 = ft_create_room(name_r2, 0, 0);
	r3 = ft_create_room(name_r3, 0, 0);
	r4 = ft_create_room(name_r4, 0, 0);
	r5 = ft_create_room(name_r5, 0, 0);
	r6 = ft_create_room(name_r6, 0, 0);
	r7 = ft_create_room(name_r7, 0, 0);
	r8 = ft_create_room(name_r8, 0, 0);
	r9 = ft_create_room(name_r9, 0, 0);
	r10 = ft_create_room(name_r10, 0, 0);
	r11 = ft_create_room(name_r11, 0, 0);
	r12 = ft_create_room(name_r12, 0, 0);
	r13 = ft_create_room(name_r13, 0, 0);
	r14 = ft_create_room(name_r14, 0, 0);
	r15 = ft_create_room(name_r15, 0, 0);

	r0->status = 0;//не забыть сразу указать особый статус для start и end
	r9->status = 2;

	r0->bfslvl = 0;//не забыть указать при парсинге bfslvl
	r9->bfslvl = MAX_INT;

	r0->next = r1;
	r1->next = r2;
	r2->next = r3;
	r3->next = r4;
	r4->next = r5;
	r5->next = r6;
	r6->next = r7;
	r7->next = r8;
	r8->next = r9;
	r9->next = r10;
	r10->next = r11;
	r11->next = r12;
	r12->next = r13;
	r13->next = r14;
	r14->next = r15;

	first = ft_create_link(r1, r0);
	second = ft_create_link(r0, r2);
	third = ft_create_link(r3, r1);
	fourth = ft_create_link(r4, r1);
	fifth = ft_create_link(r2, r4);
	sixth = ft_create_link(r5, r2);
	seventh = ft_create_link(r4, r3);
	eighth = ft_create_link(r3, r6);
	ninth = ft_create_link(r7, r3);
	tenth = ft_create_link(r4, r9);
	eleventh = ft_create_link(r8, r6);
	twelfth = ft_create_link(r8, r9);
	thirteenth = ft_create_link(r9, r7);
	fourteenth = ft_create_link(r10, r9);
	fifteenth = ft_create_link(r0, r11);
	sixteenth = ft_create_link(r11, r12);
	seventeenth = ft_create_link(r12, r13);
	eighteenth = ft_create_link(r13, r14);
	ninteenth = ft_create_link(r14, r15);
	twentienth = ft_create_link(r15, r9);

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
	ninth->next = tenth;
	tenth->next = eleventh;
	tenth->prev = ninth;
	eleventh->next = twelfth;
	eleventh->prev = tenth;
	twelfth->next = thirteenth;
	twelfth->prev = eleventh;
	thirteenth->next = fourteenth;
	thirteenth->prev = twelfth;
	fourteenth->prev = thirteenth;
	fourteenth->next = fifteenth;
	fifteenth->prev = fourteenth;
	fifteenth->next = sixteenth;
	sixteenth->next = seventeenth;
	sixteenth->prev = fifteenth;
	seventeenth->next = eighteenth;
	seventeenth->prev = sixteenth;
	eighteenth->next = ninteenth;
	eighteenth->prev = seventeenth;
	ninteenth->next = twentienth;
	ninteenth->prev = eighteenth;
	twentienth->prev = ninteenth;

	lemin->start = r0;
	lemin->end = r9;
	lemin->top_rooms = r0;
	lemin->top_links = first;
	lemin->number_of_ants = 20;

	ft_print_rooms(&(lemin->top_rooms));
	ft_print_links(&(lemin->top_links));
	
	ft_bfs(lemin);
	
	ft_del_lemin(&lemin);

/*	t_room	*a;
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
	
	ft_del_lemin(&lemin);
*/	return (0);
}
