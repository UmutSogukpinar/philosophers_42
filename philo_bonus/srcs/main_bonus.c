#include "philosophers_bonus.h"
#include "stdlib.h"


int	main(int argc, char **argv)
{
	t_table	*table;

	if (!(argc == 5 || argc == 6))
		return (display_err_msg(INV_ARGC));
	if (!check_args(argc, argv))
		return (display_err_msg(INV_ARGV));
	table = ft_calloc(1, sizeof(t_table));
	if (!table)
	{
		display_err_msg(ALLOC_ERR);
		return (EXIT_FAILURE);
	}
	if (!init_table(table, argc, argv))
		return (EXIT_FAILURE);
	//display_table(table);
	init_dining(table);
	free_table(table);
	return (EXIT_SUCCESS);
}
