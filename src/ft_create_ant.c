#include "ft_lemin.h"

void        ft_add_ant(t_ant **head, t_ant **tail, t_ant *ant)
{
    if (head && tail)
    {
        if (*head == NULL && *tail == NULL)
        {
            *head = ant;
            *tail = *head;
        }
        else if (*tail != NULL)
        {
            (*tail)->next = ant;
            ant->prev = *tail;
            *tail = ant;
        }
    }
}

void        ft_del_ant(t_ant **ant)
{
    if (ant && *ant)
    {
        (*ant)->cur_location = NULL;
        (*ant)->i = 0;
        (*ant)->next = NULL;
        (*ant)->prev = NULL;
        free(*ant);
        *ant = NULL;
    }
}

void        ft_del_ants(t_ant **top)
{
    t_ant   *tmp;

    if (top && *top)
    {
        while ((*top)->next)
        {
            tmp = (*top)->next;
            ft_del_ant(top);
            *top = tmp;
        }
        ft_del_ant(top);
        *top = NULL;
    }
}

t_ant       *ft_create_ant(t_fpath *cur_location, size_t i)
{
    t_ant   *new_ant;

    new_ant = (t_ant *)malloc(sizeof(t_ant) * 1);
    if (!new_ant)
        return (NULL);
    new_ant->cur_location = cur_location;
    new_ant->i = i;
    new_ant->next = NULL;
    new_ant->prev = NULL;
    return (new_ant);
}

void        ft_cleaner_ant(t_ant **tmp, t_ant **head, t_ant **tail)
{
    t_ant   *tmp_next;

    if (head && tail)
    {
        if ((*tmp)->prev == NULL && (*tmp)->next != NULL)
        {
            ((*tmp)->next)->prev = NULL;
            *head = (*tmp)->next;
            ft_del_ant(tmp);
            *tmp = *head;
        }
        else if ((*tmp)->prev == NULL && (*tmp)->next == NULL)
        {
            (*head) = NULL;
            (*tail) = NULL;
            ft_del_ant(tmp);
        }
        else if ((*tmp)->prev != NULL && (*tmp)->next != NULL)
        {
            ((*tmp)->prev)->next = (*tmp)->next;
            ((*tmp)->next)->prev = (*tmp)->prev;
            tmp_next = (*tmp)->next;
            ft_del_ant(tmp);
            *tmp = tmp_next;
        }
        else if ((*tmp)->next == NULL)
        {
            *tail = (*tail)->prev;
            ((*tmp)->prev)->next = NULL;
            ft_del_ant(tmp);
        }
    }
}