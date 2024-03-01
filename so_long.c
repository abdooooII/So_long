#include "so_long.h"

int main (int ac, char **av)
{
	t_list	vars;
	if (ac != 2)
		ft_error("Error: Invalid number of arguments\n");
	vars.C = 0;
	vars.E = 0;
	vars.P = 0;
	parsing(av, &vars);
}
