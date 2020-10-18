/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:18:37 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/07 21:53:35 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "ft_printf.h"
# include "libft.h"
# define BUFF_SIZE 1
# define MAS_SIZE 12000
# define MAX_INT 2147483647

typedef struct		s_room
{
	char			*name;
	int				status;
	int				x;
	int				y;
	int				visited;
	int				flag_v;
	size_t			links_count;
	t_list			*neighbours;
	struct s_room	*next_room;
	struct s_room	*prev_room;
	struct s_room	*next_in_list;
}					t_room;

typedef struct		s_tree
{
	t_room			*room;
	size_t			num_of_childs;
	t_room			*intersection;
	int				len;
	struct s_tree	*parent;
}					t_tree;

typedef struct		s_link
{
	t_room			*begin;
	t_room			*end;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_fpath
{
	t_room			*room;
	struct s_fpath	*next;
}					t_fpath;

typedef struct		s_ant
{
	t_fpath			*cur_location;
	size_t			i;
	struct s_ant	*next;
	struct s_ant	*prev;
}					t_ant;

typedef struct		s_path
{
	int				len;
	t_fpath			*top_fpath;
}					t_path;

typedef struct		s_out
{
	char			*content;
	struct s_out	*next;
	struct s_out	*prev;
}					t_out;

typedef struct		s_group
{
	size_t			num_of_turns;
	size_t			num_of_paths;
	int				*ants;
	t_path			**paths;
}					t_group;

typedef struct		s_lemin
{
	t_room			*start;
	t_room			*end;
	t_room			*top_rooms;
	t_link			*top_links;
	t_group			*best_group;
	t_ant			*head_ants;
	t_ant			*tail_ants;
	unsigned int	num_of_ants;
	unsigned int	ants_at_the_end;
	char			*line;
	t_out			*output;
	int				flag_end_begin;
	int				visual;
	int				flag_err;
}					t_lemin;

void				check_input(t_lemin *lemin);
void				is_digits(t_lemin *lemin);
void				ft_error(char *error);
void				ft_parse_command(t_lemin *lemin, int i);
void				start_and_end(t_lemin *lemin, char flag);
void				parse_room(t_lemin *lemin);
void				write_room(t_lemin *lemin);
void				free_str(char **str);
void				add_list_room(t_room **top_rooms, t_room *room);
void				add_list_links(t_link **top_links, t_link *link);
void				while_str(t_lemin *lemin, char **str, int i);
void				check_room_dup(t_room *lst, t_room *new_r);
int					check_room_or_link(t_lemin *lemin, int i);
void				write_link(t_lemin *lemin);
void				create_link(t_lemin *lemin);
void				check_links_dup(t_link *lst, t_link *new_l);
t_room				*find_room(t_lemin *lemin, char *name);
int					get_next_line(const int fd, char **line);
t_out				*ft_create_out(char *cont);
t_out				*ft_add_out(t_out *out, char *str);
int					isdigit_my(char **str, int i);
void				ft_del_output(t_out **out);
int					ft_val_overflow(char *s);
int					start_end(t_lemin *lemin);
void				ft_print_input(t_lemin *lemin);
void				ft_free(char *start_name, char *end_name);
/*
** ft_solution.c
*/
int					ft_solution(t_lemin *lemin);

/*
** ft_build_group.c
*/
t_group				*ft_build_group(t_lemin *lemin, size_t max_num_of_paths);
t_path				*ft_bfs_tree(t_lemin *lemin);

/*
** ft_create_ant.c
*/
void				ft_cleaner_ant(t_ant **tmp, t_ant **head, t_ant **tail);

/*
** ft_create_ant.c
*/
t_ant				*ft_create_ant(t_fpath *cur_location, size_t i);
void				ft_del_ants(t_ant **top);
void				ft_del_ant(t_ant **ant);
void				ft_add_ant(t_ant **head, t_ant **tail, t_ant *ant);

/*
** ft_create_gpaths.c
*/
void				ft_create_gpaths(t_room *start, t_group *group);
size_t				ft_count_gpaths(t_room *start);
t_path				*ft_assemble_path(t_room *src, t_room *dst);

/*
** ft_create_group.c
*/
t_group				*ft_create_group(t_lemin *lemin);
void				ft_count_turns(t_group *group);
void				ft_del_group(t_group *group);

/*
** ft_create_link.c
*/
t_link				*ft_create_link(t_room *begin, t_room *end);
void				ft_del_link(t_link **link);
void				ft_del_links(t_link **head);

/*
** ft_create_nodes.c
*/
t_path				*ft_add_nodeslst(t_lemin *lemin, t_list **nodes,
											t_list **next_nodes);
t_path				*ft_add_node(t_lemin *lemin, t_tree *node,
											t_list **next_nodes);

/*
** ft_create_path.c
*/
t_path				*ft_create_path(void);
void				ft_addelem_path(t_path *path, t_room *room);
t_fpath				*ft_create_fpath(t_room *room);
void				ft_path_modification(t_path *path);

/*
** ft_create_room.c
*/
t_room				*ft_create_room(char *name, int x, int y);
void				ft_delone_room(t_room **top_rooms, t_room *room);
void				ft_del_room(t_room **room);
void				ft_del_rooms(t_room **head);

/*
** ft_create_tree.c
*/
t_tree				*ft_new_tree_node(t_room *room);
t_tree				*ft_tree_child(t_tree *node, t_room *dst);
void				ft_del_treelvl(t_list **nodes);
void				ft_del_node(t_tree *node);

/*
** ft_del_dead_ends.c
*/
void				ft_del_dead_ends(t_room **top_rooms, t_lemin *lemin);

/*
** ft_init_lemin.c
*/
t_lemin				*ft_init_lemin(void);
void				ft_del_lemin(t_lemin **lemin);
void				ft_exit(t_lemin *lemin, int flag);

/*
** ft_manipulate_ant.c
*/
void				ft_distrib_ants(t_group *g, size_t num_of_ants);
void				ft_manipulate_ant(t_lemin *lemin, t_group *g);

/*
** ft_navigation.c
*/
t_tree				*ft_navigate(t_tree *node, t_room *dst);
t_path				*ft_complete_path(t_tree *node);
t_tree				*ft_ret_navig_tostart(t_lemin *lemin, t_tree *node);

/*
** ft_path_utils.c
*/
void				ft_del_path(t_path *path);
void				ft_sortarr_paths(t_path **paths, size_t size);

/*
** ft_print_path.c
*/
void				ft_print_path(t_path *path);
void				ft_print_fpath(t_fpath **top_fpath);

/*
** ft_print.c
*/
void				ft_print_links(t_link **head);
void				ft_print_rooms(t_room **head);
void				ft_print_room_links(t_list **links);
void				ft_print_group(t_group *group);
void				ft_print_input(t_lemin *lemin);

/*
** ft_solution_utils.c
*/
void				ft_visit(t_tree *node);
void				ft_reset_v(t_lemin *lemin);
int					ft_move_free(t_tree *node, t_room *dst);
int					ft_intersect(t_room *src, t_room *dst);

/*
** ft_solution.c
*/
int					ft_solution(t_lemin *lemin);

#endif
