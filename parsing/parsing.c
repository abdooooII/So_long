/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:08 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/30 20:52:08 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**parsing(char **av, t_list *vars, t_libx *mlx)
{
	int		fd;
	char	**mapp;

	check_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("file descriptor fail\n");
	vars->my_map = read_map(fd, av[1]);
	if (!vars->my_map)
		ft_error("error while reading the map\n");
	check_spaces(vars);
	check_map_characters(vars);
	check_invalid_characters(vars);
	check_walls(vars);
	check_sides(vars);
	check_map_width(vars);
	validpath_checker(vars);
	
	mapp = vars->my_map; // Assigning the map to mapp

	mlx->map = mapp;
	map_dimension(mlx);
	return (mapp);
}
