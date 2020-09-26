#include "ft_lemin.h"

int		ft_val_overflow(char *s)
{
	int	size;
	int	nb;

	if (ft_strlen(s) > 10)
		return (0);
	nb = ft_atoi(s);
	size = ft_strlen(s);
	if (nb == -1 && size != 2)
		return (0);
	return (1);
}
