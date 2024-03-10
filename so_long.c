#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	vars;
	// t_libx	*libx;

	// libx = NULL;
	if (ac != 2)
		ft_error("Error: Invalid number of arguments\n");
	vars.c = 0;
	vars.e = 0;
	vars.p = 0;
	parsing(av, &vars);

	// my_mlx(libx);
}
