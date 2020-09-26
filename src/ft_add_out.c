#include "ft_lemin.h"

t_out		*ft_add_out(t_out *out, char *str)
{
	t_out	*curr;

	curr = (t_out*)malloc(sizeof(t_out) * 1);
	if (!curr)
		return (NULL);
	out->next = curr;
	curr->content = ft_strdup(str);
	curr->prev = out;
	curr->next = NULL;
	return (curr);
}

t_out		*ft_create_out(char *cont)
{
	t_out	*new;

	new = (t_out*)malloc(sizeof(t_out) * 1);
	if (!new)
		return (NULL);
	new->content = ft_strdup(cont);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_del_Outputs(t_out **out)
{
	if (out != NULL && *out)
	{
		ft_strdel(&((*out)->content));
		(*out)->next = NULL;
		(*out)->prev = NULL;
		free(*out);
		(*out) = NULL;
	}
}

void		ft_del_Output(t_out **out)
{
	t_out	*tmp;

	if (out != NULL && *out)
	{
		while ((*out)->prev)
		{
			tmp = (*out)->prev;
			ft_del_Outputs(out);
			*out= tmp;
		}
		ft_del_Outputs(out);
		*out = NULL;
	}
}
