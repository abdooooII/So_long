/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:12 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/28 11:41:09 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	vars;
	t_libx	mlx;
	char **map;
	// t_libx	*libx;
	mlx.moves = 0;
	// libx = NULL;
	if (ac != 2)
		ft_error("Error: Invalid number of arguments\n");
	vars.c = 0;
	vars.e = 0;
	vars.p = 0;
	map = parsing(av, &vars, &mlx);
	start_map(map, mlx);
	
    mlx_hook(mlx.win, 17, 0, destroy_helper, &mlx);
	mlx_loop(mlx.mlx);

}
