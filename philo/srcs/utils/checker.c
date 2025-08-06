#include "philosophers.h"

static void		str_rtrim(char *str);
static t_bool	check_limit(char *arg);
static t_bool	check_validation(char *arg);

t_bool	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		str_rtrim(argv[i]);
	i = 0;
	while (++i < argc)
	{
		if (!check_validation(argv[i]) || !check_limit(argv[i]))
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	check_validation(char *arg)
{
	int	i;

	if (!arg)
		return (FALSE);
	i = 0;
	while (arg[i] && ft_isspace(arg[i]))
	{
		i++;
	}
	if (arg[i] && arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_limit(char *arg)
{
	size_t	value;
	size_t	len;
	size_t	billion_len;
	size_t	i;

	i = 0;
	while (ft_isspace(arg[i]))
	{
		i++;
	}
	len = ft_strlen(arg + i);
	billion_len = ft_strlen(A_BILLION);
	if (len > billion_len)
		return (FALSE);
	value = ft_atoui(arg + i);
	if (value > MAX_INT || value <= 0)
		return (FALSE);
	return (TRUE);
}

static void	str_rtrim(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_isspace(str[i]))
	{
		str[i] = '\0';
		i--;
	}
}
