#include "ft_lemin.h"

void        ft_distrib_ants(t_group *g, size_t num_of_ants)
{
    size_t  i;
    size_t  free_ants;

    free_ants = num_of_ants;
    while (free_ants > 0)
    {
        i = 0;
        while (i < g->num_of_paths - 1)
        {
            if (g->paths[i]->len + g->ants[i] <
                    g->paths[i + 1]->len + g->ants[i + 1])
                break ;
            i++;
        }
        g->ants[i]++;
        free_ants--;
    }
}