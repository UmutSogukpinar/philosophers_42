#include "philosophers_bonus.h"

t_bool	ft_isspace(char c)
{
	char	*space_set;
	int		i;

	space_set = " \t\n\v\f\r";
	i = 0;
	while (space_set[i])
	{
		if (c == space_set[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	ft_isdigit(char c)
{
	return ((int)c >= 48 && (int)c <= 57);
}
