#include "ft_lemin.h"

void    ft_zero_bfslvl(t_lemin *lemin, t_list **nodes)
{
    t_tree  *tree_node;

    tree_node = ft_new_tree_node(lemin->start);
    tree_node->len = 1;
    ft_lstadd(nodes, ft_lstnew(tree_node, sizeof(t_tree)));
}

t_path  *ft_bfs_tree(t_lemin *lemin)
{
    t_path  *path;
    t_list  *nodes;
    t_list  *next_nodes;

    ft_reset_v(lemin);
    nodes = NULL;
    ft_zero_bfslvl(lemin, &nodes);
    next_nodes = NULL;
    path = NULL;
    while (1)
    {
        path = ft_add_nodeslst(lemin, &nodes, &next_nodes);
        ft_del_treelvl(&nodes);
        if (path)
        {
            ft_del_treelvl(&next_nodes);
            return (path);
        }
        if (next_nodes == NULL)
            return (NULL);//больше не нашли нод(линков)
        nodes = next_nodes;
        next_nodes = NULL;
    }
    return (path);
}

t_group *ft_build_group(t_lemin *lemin, size_t max_num_of_path)
{
    size_t  i;
    t_path  *path;
    t_group *best;
    t_group *tmp;

    i = 0;
    best = NULL;
    while (i < max_num_of_path)
    {
        if (!(path = ft_bfs_tree(lemin)))
            break ;
        ft_path_modification(path);//обновить next_room и prev_room у комнат
        tmp = ft_create_group(lemin);//создать группу
 //       ft_print_group(tmp);//можно делать опционально в виде бонуса
        ft_del_path(path);
        if (!best)
            best = tmp;
        else if (best->num_of_turns > tmp->num_of_turns)
        {
            ft_del_group(best);
            best = tmp;
        }
        else
            ft_del_group(tmp);
        i++;
    }
    return (best);
}