#include "philosophers_bonus.h"
#include "stdio.h" // ! For debug
#include "unistd.h"

// static const char	*get_status_msg(t_status status);

t_bool	display_err_msg(char *msg)
{
	ft_putendl(DEFAULT_ERR_MSG, STDERR_FILENO);
	ft_putendl(ERROR_BAR, STDERR_FILENO);
	if (msg)
		ft_putendl(msg, STDERR_FILENO);
	ft_putendl(ERROR_BAR, STDERR_FILENO);
	return (FALSE);
}
