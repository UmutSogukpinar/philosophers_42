#include "philosophers.h"
#include "stdlib.h"


int	main(int argc, char **argv)
{
	t_table	*table;

	if (!(argc == 5 || argc == 6))
		return (display_err_msg(INV_ARGC));
	if (!check_args(argc, argv))
		return (display_err_msg(INV_ARGV));
	table = init_table(argv, argc);
	if (!table)
		return (EXIT_FAILURE);
	if (!init_dining(table))
	{
		free_table(table);
		return (EXIT_FAILURE);
	}
	//display_table(table);
	free_table(table);
	return (EXIT_SUCCESS);
}
